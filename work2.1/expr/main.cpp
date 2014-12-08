#include <stdio.h>
#include <string.h>
#include "expr.h"

int main()
{
    char *expr1 = "0";
    char *expr2 = "1+1";
    char *expr3 = "2*3-5+7/2";

    printf("%10s = %-4d (answer: 0)\n", expr1, Eval(expr1, strlen(expr1)));
    printf("%10s = %-4d (answer: 2)\n", expr2, Eval(expr2, strlen(expr2)));
    printf("%10s = %-4d (answer: 4)\n", expr3, Eval(expr3, strlen(expr3)));

    return 0;
}
