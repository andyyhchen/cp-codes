#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,in[100000];
	while(~scanf(" %d", &n))
	{
	    for(int i = 0; i < n; i++) scanf(" %d", in + i);
	  	sort(in, in + n);
		for(int i = 0; i < n; i++) printf("%d ", in[i]);
	    printf("\n");
	}
	return 0;
}
