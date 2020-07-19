#include <iostream>

using namespace std;

int main()
{
    const char encode[45]="234567890-=\\ertyuiop[]dfghjkl;'cvbnm,./";
 	const char decode[45]="`1234567890-qwertyuiopasdfghjklzxcvbnm,";
	char c,i;
 	while(~scanf("%c",&c)&&!(i=0))
 	{
		while(encode[i]!=c&&encode[i++]);
	    if(i^40)printf("%c",decode[i]);
	    else printf("%c",c);
	}
	return 0;
}
