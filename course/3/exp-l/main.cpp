#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"
#include "exp.h"

int main()
{	char exp[1024] ={0};
    	//puts("start");
    	char postexp[1024]={0};
	while(scanf("%s",exp) == 1)
	{	trans(exp,postexp);
		//DispStack(s);
		printf("\tpostexp:%s\n",postexp);
		//printf("\tcompvalue:%s\n",compvalue(postexp));
	}
	return 0;
}
