#include<stdio.h>
int stack[100] = {-1}, top = 0;
int push(int in)
{
	if(top > 99)
	    return 0;
	else
		stack[top] = in;
		top++;
	if(top == 100)
	    top = 99;
	return 1;
}

int pop(void)
{
	if(top < 0)
	    return 0;
 	else
		top--;
        printf("%d\n", top);
	return stack[top + 1];
}

int main()
{
	

    return 0;
}
