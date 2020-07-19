/*
Problem: Q490.cpp
Author: andyisman
Complete time: Sat Jan 16 18:09:24 2010
*/

#include <iostream>
#define Max 101

using namespace std;

int main()
{
	char in[Max][Max];
	while(1)
	{
		memset(in, 0, sizeof(in));
		if(!gets(in[0])) break;
		int i = 1;
		int len = strlen(in[0]),tmp;
		for(i = 1;gets(in[i]); i++)
		{
			tmp = strlen(in[i]);
			if(tmp > len) len = tmp;
		}
		for(int j = 0; j < len; j++)
		{
			int f = 0;
			for(int k = i - 1; k >= 0; k--)
			{
				if(in[k][j])
				{
					f = 1;
					printf("%c", in[k][j]);
				}
				else
				{
					printf(" ");
				}
			}
			if(!f) break;
			printf("\n");
		}


	}
}
