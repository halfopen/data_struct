#include "expr.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* -BLOCK----------- 如果需要, 你可以调用以下函数 ----------------- */

// 将由数字字符组成的 arr 转为数字, n 为 arr 的长度
static int NumFromArray(const char * const arr, int n);

// 根据运算符 op 进行运算, 获得运算结果
static int Calc(int a, int b, char op);

/* -END OF BLOCK--------------------------------------------------- */


/* -BLOCK---- 如果需要, 请在此加入你的数据结构及函数声明 ---------- */






/* -END OF BLOCK--------------------------------------------------- */


/* -BLOCK-------------- 必须通过此函数返回结果 -------------------- */
int Eval(const char* const expr, int n) // 请参阅 expr.h 的注释
{	int answer = 0, num_len = 0, i = 0, a = 0, b = 0,t_i=0;//num_len数字长度,i遍历,a暂时保存数字
    	char t_exp[1024]={0}, op;//保存只有+-的表达式
    	int t_n = 0;
    	while(*(expr+i)>='0' && *(expr+i) <= '9' && i<n)
    	{	i++;	
		num_len++;
    	}
	a = NumFromArray( expr, num_len);
	*t_exp = a+1;//数值都多一,防止出现0
    	while( *(expr+i) && i<n)//遍历
    	{	op = *(expr+i);		//得到一个操作符
        	i++;
		t_i=i;	//保存i的位置
        	num_len = 0;
		while(*(expr+i)>='0' && *(expr+i) <= '9' && i<n)
    		{	i++;	
			num_len++;
    		}
		b = NumFromArray( expr+t_i, num_len);	//得到一个数字
        	if(op=='/'|| op =='*')
        	{	a=Calc(a,b,op);
			*(t_exp+t_n) = a+1;
		}
        	else
		{	*(t_exp+t_n+1)=op;
			*(t_exp+t_n+2)=b+1;
			t_n+=2; 
		}
		if(i>=n)
		{	i=1;answer = *t_exp-1;
			while(i<=t_n)
			{	op = *(t_exp+i);
				b = *(t_exp+i+1)-1;
				answer = Calc(answer,b,op);
				i += 2;
			}
			break;
		}
    	}
    	return answer;
}
/* -END OF BLOCK--------------------------------------------------- */

/* -BLOCK------- 如果需要, 请在此加入你已声明的函数实现 ----------- */





/* -END OF BLOCK--------------------------------------------------- */

static int NumFromArray(const char * const arr, int n)
{
    assert(n > 0);

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < '0' || arr[i] > '9')
        {
            fprintf(stderr, "NumFromArray: bad input - not a digit '%c'\n", arr[i]);
            exit(-1);
        }
        num *= 10;
        num += arr[i] - '0';
    }
    return num;
}

static int Calc(int a, int b, char op)
{
    switch (op) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    default:
        fprintf(stderr, "Calc: bad input - operation '%c'\n", op);
        exit(-2);
    };
}
