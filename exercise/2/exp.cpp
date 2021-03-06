/*	function:Expression value----main_function_cpp
**	time:2014-10-09- 16:04
**	author:halfopen
**	version:1
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "LiStack.h"
#include "exp.h"
#define PI 3.14159265452
#define Size 18
struct stack
{     char ch;
       int pri;
}lpri[Size] = {{'=',0} , {'(',1} ,{'a',1}, {'b',1},{'c',1},{'d',1},{'e',1},{'f',1},{'g',1},{'h',1},{'i',1},{'*',5},{'%',5} ,{'^',5}, {'/',5} , {'+',3} , {'-',3} , {')',6}},
rpri[Size] = {{'=',0} , {'(',6} , {'*',4} ,{'%',4}, {'^',4},{'/',4} , {'+',2} , {'-',2} , {')',1},{'a',6},{'b',6},{'c',6},{'d',6},{'e',6},{'f',6},{'g',6},{'h',6},{'i',6}};

int leftpri( char op)
{   int i;
    for( i=0; i<Size; ++i)
    {    if(lpri[i].ch == op)return lpri[i].pri;
    }
	return 0;
}
int rightpri( char op)
{   int i;
    for( i=0; i<Size; ++i)
    {    if(rpri[i].ch == op)return rpri[i].pri;
    }
    return 0;
}

bool InOp(char ch)
{    if( ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch =='/' || ch =='%')
     {   return true;}
     else {return false;}
}
int Precede(char op1, char op2)
 {   if(leftpri(op1)== rightpri(op2) )
         return 0;
    else if(leftpri(op1)< rightpri(op2))
         return -1;
    else return 1;
}

void expTurn(char *exp)//add () after a fun like sin5 -> sin(5) -5 -> -(6)
{	char s[1024];
	bool fun = false;
	unsigned int i=0,j=0;
	while(exp[i]){s[i]=exp[i];i++;}
	s[i]='\0';
	for(i=0,j=0;i<=strlen(exp);i++,j++)
	{	exp[j] = s[i];
		//printf("exp: %c j:%d\n",exp[j],j);
		if(s[j] == '-' &&  ( j==0   ||  ( j>0&&(exp[j-1]>'9'||exp[j-1]<'0'))             ))
		{/*puts("i:");*/exp[j]='i';exp[++j]='(';fun = true;continue;}
		if( ( (s[i]>='a'&&s[i]<='z')) && s[i+1]>='0'&&s[i+1]<='9')//sin4	
		{	exp[++j] = '(';	fun = true; continue;}
		else if(fun && (s[i+1]<'0'||s[i+1]>'9'))
		{	exp[++j] = ')'; fun = false; continue;}
	}
} 
bool isFun(char c)
{	if( c>='a'&& c<='i')return true;
	return false;
}

/*
exp:-(2).3536
	postexp:2#.3536#-
Empty
	compvalue:-1.9999

1+(-(2))+3
exp:1+(-(2))+3
	postexp:1#2#-+3#+
	compvalue:3

*/
void trans( char *exp, char postexp[]) // abs sqrt exp ln log sin cos tanh
{   int i = 0,j=0;
    LiStack *op;
	InitStack(op);
	Push(op,'=');
	char c,f[1024]={0};
    while( *exp != '\0')
    {	if( !InOp( *exp) || (*exp >= 'a' && *exp <= 'z')) 	// if not operate
             	{	while( (*exp>= '0' && *exp<= '9') || *exp=='.')
                  	{ 	postexp[i++] = *exp;
                         	exp++;	//number
                  	}
			if( *exp >= 'a' && *exp <= 'z')
			{	//printf("f:%s \t\texp:%s i:%d\n",f,exp,i);
                for(j = 0; j<1024 ; ++j)
				{	if('(' == *exp){f[j] = '\0';break;}
					f[j] =*(exp++);
					//printf("\t\t\t\tf&e:%c\t",f[i]);
				}
				if(strcmp(f,"abs") == 0){Push(op,'a');exp++;continue;}
				else if(strcmp(f,"sqrt") == 0){Push(op,'b');exp++;continue;}
				else if(strcmp(f,"exp") == 0){Push(op,'c');exp++;continue;}
				else if(strcmp(f,"ln") == 0){Push(op,'d');exp++;continue;}
				else if(strcmp(f,"log") == 0){Push(op,'e');exp++;continue;}
				else if(strcmp(f,"sin") == 0){Push(op,'f');exp++;continue;}
				else if(strcmp(f,"cos") == 0){Push(op,'g');exp++;continue;}
				else if(strcmp(f,"tanh") == 0){Push(op,'h');exp++;continue;}
				else if(strcmp(f,"i") == 0){/*puts("i");*/Push(op,'i');exp++;continue;}
				else printf("!!Unkown Exp:%s\n",f);
				
			}	
            postexp[i++] = '#';	//apart
        }
        else
		{	GetTop(op,c);	
            switch( Precede( c, *exp))
            {  	case -1:
                {  	Push(op,*exp);  //enter
						//if(c == 'a'){puts("-1 c==a");};
                   exp++;
                }break;
                case 0:
                {	if( isFun(c) ){Pop(op,postexp[i++]);}
					else Pop(op,c);
                    exp++;
                }break;
                case 1:
                {    	//if(c == 'a'){puts("1 c==a");};
					Pop(op,postexp[i++]);
                }break;
            }
        }
		//DispStack(op);printf("postexp:%s\n",postexp);
    }
    while( GetTop(op,c), c != '=')
    {   Pop(op,postexp[i++]);
    }
    //puts("out1");
    postexp[i] = '\0';
    //puts("out2");
	//DestroyStack(op);      //这个地方出了一个很奇怪的问题 
	//puts("out");
}

double wkt( double a, double b, char o)// abs sqrt exp ln log 10 sin cos tanh
{	switch(o)
	{	case '+':
		{	return a+b;
		}break;
		case '%':
		{	return (int)b%(int)a+0.0;
		}break;
		case '-':
		{	return b-a;
		}break;
		case '*':
		{	return a*b;
		}break;
		case '/':
		{	if( 0 == a){puts("error,b=0");exit(0);}	
			else
				return b/a;
		}break;
		case 'a':	//function abs
		{	return abs(a);
		}break;
		case 'b':	//function sqrt
		{	if(a>=0)return sqrt(a);
			else puts("error,sqrt:b=0");
			exit(0);
		}break;
		case 'c':	//function a^b
		{	return exp(a);
		}break;
		case 'd':	//function ln
		{	return log(a);
		}break;
		case 'e':	//function log
		{	return log10(a);
		}break;
		case 'f':	//function sin
		{	return sin(a);
		}break;
		case 'g':	//function cos
		{	return cos(a);
		}break;
		case 'h':	//function tan
		{	return tanh(a);
		}break;
		case 'i':	//function tan
		{	return -(a);
		}break;
		default:
		{	puts("wrong operate between a and b");
			exit(0);
		}
	}
}

double compvalue( char *postexp)
{     	LiStack2 *st;
      	//puts("compare");
	unsigned int i = 0,j=0;
      	double d,a,b,c;
      	InitStack2(st);
	//DispStack2(st);
      	while( *postexp != '\0')
      	{	   	
		if( InOp(*postexp) || isFun(*postexp) )
             	{	Pop2(st,a);
             		Pop2(st,b);
             		Push2(st, wkt(a,b,*postexp) );
			//printf("\t\t\t\tc:%lf",wkt(a,b,*postexp) );
             	}
		//else if(*postexp>= '0'  &&  *postexp <= '9')Push2(st,*postexp-'0');
                else
                     {  	d = c = 0.0;
				bool getNum = false,getDot = false;
                             	while( (*postexp>= '0'  &&  *postexp <= '9') || *postexp == '.')
                             	{      	if(*postexp == '.'){postexp++;getDot = true;break;}
					d = 10*d +*postexp -'0';
                                    	postexp++;
					getNum = true;	
                             	}
				i=1;
				while( (getDot == true && *postexp>= '0'  &&  *postexp <= '9') || *postexp == '.')
				{	if(*postexp == '.'){	puts("!!Error,two '.' ");exit(0);};
					j = i;	
					b=1.0;
					while(j--)b = b/10.0;
					c =c+ (*postexp-'0')*b;
					postexp++;
					i++;
				}  
		             	if(getNum){d += c; Push2(st,d);};
                     };
             	postexp++;
		//printf("\nDispSt:");DispStack2(st);
		//printf("\npostexp: %s\n",postexp);
      	}
	//printf("\nendDispSt:");DispStack2(st);
	GetTop2(st,c);
	DestroyStack2(st);
	//c =(int)(c*10000000)/10000000.0 ;//save 7 number after .
      	return (c);
}








