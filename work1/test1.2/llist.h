#ifndef LLIST_H_
#define LLIST_H_

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LinkNode;

typedef struct LList {
    int length;
    struct LNode *first;
    struct LNode *last;
} LinkList;

/* 初始化一个链表 */
/* 时间复杂度 O(1) */
void InitList(LinkList*& L);

/* 销毁一个链表, 销毁后链表被置为 NULL */
/* 时间复杂度 O(n) */
void Destroy(LinkList*& L);

/* 判断是链表是否为空链表 */
/* 时间复杂度 O(1) */
bool ListEmpty(const LinkList* const L);

/* 获得链表长度 */
/* 时间复杂度 O(1) */
int ListLength(const LinkList* const L);

/* 输出一个链表 */
/* 时间复杂度 O(n) */
void DispList(const LinkList* const L);

/* 获得链表的第 i 个元素, 下标从 0 开始, 若下标越界则返回 false, 否则引用参数正常赋值并返回 true */
/* 时间复杂度 O(n) */
bool GetElem(const LinkList* const L, int i, ElemType &e);

/* 获得链表中第一个元素与给定元素相等的元素下标, 下标从 0 开始, 若不存在这样的元素, 返回 -1 */
/* 时间复杂度 O(n) */
int LocateElem(const LinkList* const L, const ElemType &e);

/* 在下标 i 处插入一个元素, 下标从 0 开始, 若下标越界则返回 false, 否则元素正常插入并返回 true */
/* 时间复杂度 首尾为 O(1), 中间为 O(n) */
bool ListInsert(LinkList* &L, int i, const ElemType &e);

/* 删除链表的第 i 个元素, 下标从 0 开始, 若下标越界则返回 false, 否则元素被正常删除并返回 true */
/* 时间复杂度 O(n) */
bool ListDelete(LinkList *&L, int i, ElemType &e);

#endif
