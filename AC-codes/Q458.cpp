/*
Problem: Q458.cpp
Author: andyisman
Complete time: Sat Jan 16 18:09:19 2010
*/

#include <stdio.h>
int main(char c)
{
	while(~scanf("%c", &c))printf("%c",c-7*(c!='\n'));
	return 0;
}
