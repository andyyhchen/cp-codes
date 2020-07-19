#include <iostream>

using namespace std;

int main()
{
	char ch[150];
	int count=0;
	while(~scanf(" %s",ch))
	{
		for(int i=0;ch[i];i++)
		{
			if(isdigit(ch[i])) count+=(ch[i]-'0');
			if(ch[i]=='b') while(count--)printf(" ");
			if(ch[i]=='!') printf("\n");
			if((isalpha(ch[i])||ch[i]=='*')&&ch[i]!='b') while(count--) printf("%c",ch[i]);
		}
	}
	
	return 0;
}
