#include <iostream>

using namespace std;

int main(int t)
{
	char s[100];
	while(~scanf(" %d", &t))
	{
		for(int i = 0; i < t; i++)
		{
			scanf(" %s", s);
			printf("%s, ", s);
			printf("happy new year!!!\n");
		}
	}
	return 0;
}
