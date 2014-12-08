/*
	time:2014-10-05 14:45
	author:halfopen
	version: 1

*/

#include <stdio.h>
#include <stdlib.h>
#include "readInput.h"

int readInput(int *&a)
{	int length,n;	
	FILE *input;
	input = fopen("input.txt","r");

	fscanf(input, "%d", &length );
	a = (int *)malloc( sizeof(int)*length );
	for(n=0;n<length;++n)fscanf(input,"%d",a+n);
	fclose( input );
	return length;
}
