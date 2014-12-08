#ifndef _BTREE_H_
#define _BTREE_H_

//节点定义 
typedef char ElemType;
typedef struct node
{       ElemType data;
        struct node * lchild;
        struct node * rchild;
}BTNode;

//创建二叉树 
void CreateBTNode(BTNode *& b, char * str);

//查找节点
BTNode * FindNode(BTNode * b, ElemType x);

//找孩子节点
BTNode * LchildNode(BTNode * p);
BTNode * RchildeNode(BTNode * p);


//查找所有双亲
int FindParents(BTNode *b, ElemType x, char *path, int  pathlen);

//查找所有孩子
int  FindKids(BTNode *b, char *path);

//求高度
int BTNodeHeight(BTNode *b); 

//输出二叉树
void DispBTNode(BTNode * b); 

//凹入表示法
void DispBTNode1(BTNode * b, int l); 

//遍历

//先序遍历
void PreOrder(BTNode *b);

//中序遍历 
void InOrder(BTNode *b);
 
// 后序遍历 
void PostOrder(BTNode *b);

//输出所有叶子节点
void DispLeaf(BTNode *b); 

//求节点值为x的节点的层数
int Level(BTNode *b, ElemType x, int h); 
#endif
