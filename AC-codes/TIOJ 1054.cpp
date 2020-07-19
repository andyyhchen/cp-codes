#include <stdio.h>
#include <string.h>
const char table[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main()
{
	char in[10];
	int d;
	while(~scanf(" %s %d", in, &d))
	{
		int i; d %= 7;
		for(i = 0; i < 7; i++) if(!strcmp(in, table[i])) break;
		printf("%s\n",table[(i+d)%7]);
	}
	return 0;
}
