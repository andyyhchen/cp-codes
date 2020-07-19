#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int degree = 0, sum, tmp, i;
	char s[1001];
	while(gets(s))
	{
		if(!(s[0] - '0')) break;
		sum = degree = 0;
		for(i = 0; s[i]; i++)
		    sum += s[i] - '0';
		while(1)
		{
			tmp = 0;
			if(sum % 9) break;
			if(!(sum ^ 9)){ degree++; break;}
			degree++;
			while(sum)
			{
				tmp += sum % 10;
				sum /= 10;
			}
			sum = tmp;
		}
		if(degree)
		    printf("%s is a multiple of 9 and has 9-degree %d.\n", s, degree);
		else
			printf("%s is not a multiple of 9.\n", s, degree);
	}
    return 0;
}
