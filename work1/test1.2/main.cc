#include <cstdio>
#include <cstdlib>
#include "llist.h"
#include "listset.h"

int main() {
	int n, m;
	int temp;
	LinkList *A, *B, *S = NULL, *U = NULL, *D = NULL;

	// 初始化两个列表用于存放初始集合
	InitList(A);
	InitList(B);

	// 获取两个集合的大小
	scanf("%d%d", &n, &m);

	// 读入集合 A, 假设输入是已排序的, 并且不存在重复的元素
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		ListInsert(A, i, temp);
	}

	// 读入集合 A, 假设输入是已排序的, 并且不存在重复的元素
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		ListInsert(B, i, temp);
	}

	// 计算交、并、差
	Intersection(S, A, B);
	Union(U, A, B);
	Difference(D, A, B);

	// 输出结果
	printf("Set A (Size %d): \n\t", ListLength(A));
	DispList(A);
	printf("Set B (Size %d): \n\t", ListLength(B));
	DispList(B);
	printf("\n");

	printf("A ^ B (Size %d): \n\t", ListLength(S));
	DispList(S);

	printf("A U B (Size %d): \n\t", ListLength(U));
	DispList(U);

	printf("A - B (Size %d): \n\t", ListLength(D));
	DispList(D);

	return 0;
}
