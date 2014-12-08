/*	
**	数据结构综合实验3-二叉树实现家谱的相关运算
**	time:2014-11-26 20:43
**	author:halfopen
**	version:1
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "fileOperate.h"

//家谱的最大长度
#define MaxSize 1024 

void printMenu();
int main()
{	char choose ,s[MaxSize]="A(B(D(,G)),C(E,F))", x;
	char path[MaxSize];		//保存路径	
	int pathlen;			//位置
    int find = 0;	
	BTNode *b, *p;
	readData(s);			//从文件中读取
    CreateBTNode(b, s);		//创建二叉树
	while(printMenu(),puts("Enter your choice"),choose=getchar())
	{	
		switch(choose)
		{	case '1':	//括号输出
			{	 DispBTNode(b);
				puts("");
			}break;
			case '2':	//凹入输出
			{	 DispBTNode1(b, 0);
				puts("");
			}break;
			case '3':	//从文件中读取
			{	readData(s);
				CreateBTNode(b, s);
				puts("read completed!");
			}break;
			case '4':	//输入一个新的家谱
			{	puts("Please input a new family tree");
				scanf("%s",s);
				CreateBTNode(b, s);
				puts("Family tree updated");
				
			}break;
			case '5':	//查找孩子
			{	getchar();	
				puts("Please input the node you want to find:");				
				scanf("%c",&x);
                p = FindNode(b,x);
                memset(path,0,sizeof(path));
                FindKids(p->rchild,path);
			    puts("\nKids:");
				printf("%s",path);
				puts("\n");
				
			}break;
			case '6':	//查找双亲
			{	getchar();	
				puts("Please input the node you want to find:");				
				scanf("%c",&x);
				pathlen = 0;
                memset(path,0,sizeof(path));
				find = FindParents(b, x, path, pathlen);
				printf("\nfind=%d\n",find);
                puts("\nParents:");
				printf("%s",path);
				puts("\n");
				
			}break;
			case '7':	//清除数据
			{	clearData();
				puts("Cleared");
			}break;
			case '8':	//保存家谱到文件
			{	writeData(s);
				puts("Saved");
			}break;
			case '0':	//保存家谱到文件
			{exit(0);
			}break;
			default:
			{continue;}
		}
		puts("press any key to continue");getchar();getchar();
	}
	return 0;
}

//打印菜单
void printMenu()
{	puts("----------------------family tree----------------");
	puts("-\t1.show family tree---form1");
	puts("-\t2.show family tree---form2");
	puts("-\t3.read family tree from family.dat");
	puts("-\t4.insert new family tree");
	puts("-\t5.find son of x");
	puts("-\t6.find parents of x");
	puts("-\t7.clear all record from family.dat");
	puts("-\t8.save family tree to family.dat");
	puts("-\t0.exit");
	puts("------------------------------------------------");
}



