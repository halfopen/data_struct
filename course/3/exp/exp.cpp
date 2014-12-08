#include <stdio.h>
#include <stdlib.h>
#define Maxop 100
#define MaxSize 200
struct stack
{     char ch;
       int pri;
}lpri[16] = {{'=',0} , {'(',1} , {'*',5} , {'/',5} , {'+',3} , {'-',3} , {')',6}},
rpri[16] = {{'=',0} , {'(',6} , {'*',4} , {'/',44} , {'+',2} , {'-',2} , {')',1}};
int leftpri( char op)
{   int i;
    for( i=0; i<Maxop; ++i)
    {    if(lpri[i].ch == op)return lpri[i].pri;
    }
	return 0;
}
int rightpri( char op)
{   int i;
    for( i=0; i<Maxop; ++i)
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
void trans( char *exp, char postexp[])
{     struct
      {     char data[MaxSize];
            int top;
      }op;
      int i = 0;
      op.top = -1;
      op.top++;
      op.data[op.top]= '=';
      while( *exp != '\0')
      {      if( !InOp( *exp))
             {   while( *exp>= '0' && *exp<= '9')
                  {      postexp[i++] = *exp;
                         exp++;//number

                  }
                  postexp[i++] = '#';//after
             }
             else
             {   switch( Precede( op.data[op.top], *exp))//error here
                 {       case -1:
                         {    op.top++;op.data[op.top] = *exp;
                          exp++;
                          }break;
                          case 0:
                          {    op.top--;
                          exp++;
                          }break;
                          case 1:
                          {    postexp[i++] = op.data[op.top];//before
                                op.top--;
                          }break;
                          }
             }
      }
      while( op.data[op.top] != '=')
      {      postexp[i++] = op.data[op.top];
             op.top--;
      }
      postexp[i] = '\0';
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

int main()
{   char exp[] = "(56-20)/(4+2)";
    puts("start");
    char postexp[MaxSize];
    trans(exp,postexp);
    printf("%s\n",exp);
    printf("%s\n",postexp);
    printf("%g\n",compvalue(postexp));
    return 0;
}

