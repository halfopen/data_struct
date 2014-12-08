#ifndef LISTSET_H_
#define LISTSET_H_

#include "llist.h"

/* 求两个集合 A, B 的交, 结果存放于 N 中 */
void Intersection(LinkList* &N, const LinkList* const A, const LinkList* const B);

/* 求两个集合 A, B 的并, 结果存放于 N 中 */
void Union(LinkList* &N, const LinkList* const A, const LinkList* const B);

/* 求两个集合 A, B 的差 (A-B), 结果存放于 N 中 */
void Difference(LinkList* &N, const LinkList* const A, const LinkList* const B);

#endif
