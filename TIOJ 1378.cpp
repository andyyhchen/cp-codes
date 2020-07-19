#include <iostream>
using namespace std;
int priority(char a)
{
	if(a=='+'||a=='-') return 1;
	if(a=='*'||a=='/') return 2;
	return 0;
}
int main()
{
	char s[510], stack[510], top;
	while(gets(s))
	{
		top = 0;
		for(int i = 0;s[i];i++)
		{
			if(isdigit(s[i])) printf("%c",s[i]);
			else
			{
				if(s[i] == '(') stack[top++] = s[i];
				if(priority(s[i]))
				{
					while(priority(stack[top - 1]) >= priority(s[i])) printf("%c", stack[--top]);
					stack[top++] = s[i];
				}
				if(s[i] == ')')
				{
					while(stack[top - 1]!='(') printf("%c",stack[--top]);
					top--;
				}
			}
		}
		while(top) printf("%c", stack[--top]);
		printf("\n");
	}

	return 0;
}
