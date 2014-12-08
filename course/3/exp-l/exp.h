#ifndef EXP_H_
#define EXP_H_

#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"



int leftpri( char op);
int rightpri( char op);
bool InOp(char ch);
int Precede(char op1, char op2);
float wkt( float a, float b, char o);
void trans( char *exp, char postexp[]);
float compvalue( char *postexp);
#endif
