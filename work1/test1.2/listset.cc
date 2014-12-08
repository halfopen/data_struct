#include "listset.h"
#include <cstdlib>

/* 求两个集合 A, B 的交, 结果存放于 N 中 */
void Intersection(LinkList* &N, const LinkList* const A, const LinkList* const B) {
    // 这是一个示例，大家可以模仿
    InitList(N);

    LinkNode *p = A->first;
    LinkNode *q = B->first;

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else { // p->data == q->data
            ListInsert(N, ListLength(N), p->data);
            p = p->next;
            q = q->next;
        }
    }
}

/* 求两个集合 A, B 的并, 结果存放于 N 中 */
void Union(LinkList* &N, const LinkList* const A, const LinkList* const B) {
    /* ---------------- 请添加你的代码 ------------------ */




    /* ------------------------------------------------ */
}

/* 求两个集合 A, B 的差 (A-B), 结果存放于 N 中 */
void Difference(LinkList* &N, const LinkList* const A, const LinkList* const B) {
    /* ---------------- 请添加你的代码 ------------------ */




    /* ------------------------------------------------ */
}
