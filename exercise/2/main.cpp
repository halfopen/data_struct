/*	function:Expression value----main_cpp
**	time:2014-10-09- 16:04
**	author:halfopen
**	version:1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LiStack.h"
#include "exp.h"

int main()
{	char exp[1024] ={0};
    char postexp[1024]={0};
    puts("input your expression,support '+ - * / abs sin cos sqrt exp ln log tanh ( )'");
	while(scanf("%s",exp) == 1)
	{	if(*exp == '!')break;
		expTurn(exp);                    //������ʽ��������ŵ� 
		printf("Exp:%s\n",exp);          //������ʽ 
		trans(exp,postexp);              //תΪ��׺���ʽ		
		printf("Postexp:%s\n",postexp);  //�����׺���ʽ 
		printf("Result:%g\n",compvalue(postexp));//��������� 
		puts("input your expression,support '+ - * / abs sin cos sqrt exp ln log tanh ( )'");
	}
	puts("exit");
	return 0;
}
