#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LiStack.h"
#include "exp.h"

struct stack
{     char ch;
       int pri;
}lpri[7] = {{'=',0} , {'(',1} , {'*',5} , {'/',5} , {'+',3} , {'-',3} , {')',6}},
rpri[7] = {{'=',0} , {'(',6} , {'*',4} , {'/',44} , {'+',2} , {'-',2} , {')',1}};

int leftpri( char op)
{   int i;
    for( i=0; i<7; ++i)
    {    if(lpri[i].ch == op)return lpri[i].pri;
    }
	return 0;
}
int rightpri( char op)
{   int i;
    for( i=0; i<7; ++i)
    {    if(rpri[i].ch == op)return rpri[i].pri;
    }
    return 0;
}

bool InOp(char ch)
{    if( ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch =='/' )
     {   return true;}
     else {return false;}
}
int Precede(char op1, char op2)
 {   if(leftpri(op1)== rightpri(op2))
         return 0;
    else if(leftpri(op1)< rightpri(op2))
         return -1;
    else return 1;
}

void trans( char *exp, char postexp[]) // abs sqrt exp ln log 10 sin cos tanh
{   	int i = 0;
      	LiStack *op;
	InitStack(op);
	Push(op,'=');
	char c,f[8]={0};
      	while( *exp != '\0')
      	{	if( !InOp( *exp) || (*exp >= 'a' && *exp <= 'z')) 	// if no operate
             	{	while( *exp>= '0' && *exp<= '9')
                  	{ 	postexp[i++] = *exp;
                         	exp++;	//number
                  	}
			if( *exp >= 'a' && *exp <= 'z')
			{	for(i = 0; i<6 ; ++i)
				{	if(*exp < 'a' || *exp > 'z')break;
					f[i] = exp[i];
				}
				exp += i-1;
				printf("f:%s\n",f);		
			}
                  	postexp[i++] = '#';	//apart
             	}
             	else
		{ GetTop(op,c);	switch( Precede( c, *exp))
                 		{  	case -1:
                         		{  	Push(op,*exp);
                          			exp++;
                          		}break;
                          		case 0:
                          		{ 	Pop(op,c);	// ( or )
                          			exp++;
                          		}break;
                          		case 1:
                          		{    	Pop(op,postexp[i++]);
                          		}break;
                          	}
             	}
		printf("postexp:%s\n",postexp);
      	}
      	while( GetTop(op,c), c != '=')
      	{   Pop(op,postexp[i++]);
      	}
      	postexp[i] = '\0';
	DestroyStack(op);
}
/*
float wkt( float a, float b, char o)// abs sqrt exp ln log 10 sin cos tanh
{	switch(o)
	{	case '+':
		{	return a+b;
		}break;
		case '-':
		{	return a-b;
		}break;
		case '*':
		{	return a*b;
		}break;
		case '/':
		{	if( 0 == a){puts("error,b=0");exit(0);}	
			else
				return a/b;
		}break;
		case '1':	//function abs
		{	return abs(a);
		}break;
		case '2':	//function sqrt
		{	if(a>=0)return sqrt(a);
			else puts("error,sqrt:b=0");
		}break;
		case '3':	//function a^b
		{	return a^b;
		}break;
		case '4':	//function ln
		{	return ln(a);
		}break;
		case '5':	//function log
		{	return log(a);
		}break;
		case '7':	//function sin
		{	return sin(a);
		}break;
		case '8':	//function cos
		{	return cos(a);
		}break;
		case '9':	//function tan
		{	return tan(a);
		}break;
		default:
		{	puts("wrong operate between a and b");
			exit(0);
		}
	}
}


float compvalue( char *postexp)
{     struct
      {     float data[MaxSize];
            int top;
      }st;
      puts("compare");
      float d,a,b,c;
      st.top = -1;
      while( *postexp != '\0')
      {      switch( *postexp)
             {       case '+':
                     {    a = st.data[st.top];
                          st.top--;
                          b = st.data[st.top];
                          st.top--;
                          c = a+b;
                          st.top++;
                          st.data[st.top] = c;
                     }break;
                     case '-':
                     {    a = st.data[st.top];
                          st.top--;
                          b = st.data[st.top];
                          st.top--;
                          c = b-a;
                          st.top++;
                          st.data[st.top] = c;
                     }break;
                     case '*':
                     {    a = st.data[st.top];
                          st.top--;
                          b = st.data[st.top];
                          st.top--;
                          c = a*b;
                          st.top++;
                          st.data[st.top] = c;
                     }break;
                     case '/':
                     {    a = st.data[st.top];
                          st.top--;
                          b = st.data[st.top];
                          st.top--;
                          if(a != 0)
                          {    c = b/a;
                               st.top ++;
                               st.data[st.top] = c;
                          }
                          else
                          {    puts("\n /0");
                               exit(0);
                          }
                     }break;
                     default:
                     {       d = 0;
                             while( *postexp>= '0'  &&  *postexp <= '9' )
                             {      d = 10*d +*postexp -'0';
                                    postexp++;
                             }
                             st.top++;
                             st.data[st.top]=d;
                             break;
                     }

             }
	     //printf("%g\n",st.data[st.top]);
             postexp++;
      }
      return (st.data[st.top]);
}
*/







