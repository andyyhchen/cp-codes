/*
Problem: Q10499.cpp
Author: andyisman
Complete time: Sun Jan 17 14:47:58 2010
*/

#include <iostream>

using namespace std;

int main()
{
	long long int n;
	while(scanf(" %lld", &n)&&n>=0)printf("%lld%%\n",25*n*(n!=1));
	return 0;
}
