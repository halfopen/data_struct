#include "llist.h"
#include <cstdio>
#include <cstdlib>

static const char *START_DELIMITER    = "|:";
static const char *TERMINAL_DELIMITER = ":|";
static const char *NEXT_DELIMITER     = "->";

static void AssertListNotNull(const LinkList* const L) {
    if (L == NULL) {
        fprintf(stderr, "Error: Parameter must not be NULL\n");
        exit(-1);
    }
}

void InitList(LinkList*& L) {
    L = (LinkList *) malloc(sizeof(LinkList));
    L->first = L->last = NULL;
    L->length = 0;
}

void Destroy(LinkList*& L) {
    if (L == NULL) return;

    LinkNode *p = L->first; 
    while (p != NULL) {
        L->first = p->next;
        free(p);
        p = L->first;
    }
    free(L);
    L = NULL;
}

bool ListEmpty(const LinkList* const L) {
    AssertListNotNull(L);

    return (L->length == 0);
}

int ListLength(const LinkList* const L) {
    AssertListNotNull(L);

    return L->length;
}

void DispList(const LinkList* const L) {
    AssertListNotNull(L);
    
    printf("%s", START_DELIMITER);
    const char * delimiter = "\0";
    LinkNode *p = L->first;
    while (p != NULL) {
        printf("%s %d ", delimiter, p->data); 
        delimiter = NEXT_DELIMITER;
        p = p->next;
    }
    printf("%s\n", TERMINAL_DELIMITER);
}

bool GetElem(const LinkList* const L, int i, ElemType &e) {
    AssertListNotNull(L);

    if (L->length <= i || i < 0) return false;

    LinkNode *p = L->first;
    while (i > 0) {
        p = p->next;
        i -= 1;
    }
    e = p->data;

    return true;
}

int LocateElem(const LinkList* const L, const ElemType &e) {
    AssertListNotNull(L);

    LinkNode *p = L->first;
    int i = 0;
    while (p != NULL) {
        if (p->data == e) 
            return i;
        p = p->next;
        i += 1;
    }
    return -1;
}

bool ListInsert(LinkList* &L, int i, const ElemType &e) {
    AssertListNotNull(L);

    if (i < 0 || i > L->length) {
        return false;
    }

    LinkNode *newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = e;
    
    if (i == 0) {
        newNode->next = L->first;
        L->first = newNode;
        if (L->length == 0) L->last = newNode;
    } else if (i == L->length) {
        newNode->next = NULL;
        L->last->next = newNode;
        L->last = newNode;
    } else {
        LinkNode *p = L->first;
        while (--i) {
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    L->length += 1;

    return true;
}

bool ListDelete(LinkList *&L, int i, ElemType &e) {
    AssertListNotNull(L);
    if (i < 0 || i >= L->length) {
        return false;
    }

    LinkNode *delNode = NULL;
    if (i == 0) {
        e = L->first->data;
        delNode = L->first;
        L->first = delNode->next;
        if (L->first == NULL) L->last = NULL;
    } else {
        LinkNode *pre = L->first;
        while (--i) {
            pre = pre->next;
        }
        delNode = pre->next;
        pre->next = delNode->next;
        if (delNode == L->last) L->last = pre;
    }
    L->length -= 1;
    free(delNode);

    return true;
}
