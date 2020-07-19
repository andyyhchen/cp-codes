#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[150], ans = 0, i;
	for(i = 0; i < 150; i++){
		a[i] = i * i;
	}
	int f1,f2;
	for(ans = 1000; ans < 10000; ans++){
        f1 = f2 = 0;
		for(i = 0; i < 150; i++){
			if(ans+111 == a[i]) f1=1;
			if(ans+1647+111 == a[i]) f2=1;
		}
		if(f1&&f2) break;
	}
	printf("%d\n", ans);
	return 0;
}
