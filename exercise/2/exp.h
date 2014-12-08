/*	function:Expression value----main_function_h
**	time:2014-10-09- 16:04
**	author:halfopen
**	version:1
*/
#ifndef EXP_H_
#define EXP_H_

#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"

bool isFun(char c);
void expTurn(char *exp); //add () after a fun like sin5 > sin(5)
int leftpri( char op);
int rightpri( char op);
bool InOp(char ch);
int Precede(char op1, char op2);
double wkt( double a, double b, char o);
void trans( char *exp, char postexp[]);
double compvalue( char *postexp);
#endif
