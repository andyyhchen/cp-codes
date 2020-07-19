#include <iostream>

using namespace std;

long long int T[65538];

int build(void)
{
	for(int i = 1; i < 65538; i++)
		T[i-1] = i * i;
}

int Bs(int i)
{
	int s = 0, e = 65537, mid;;
	while(s <= e)
	{
		mid = (s+e)/2;
		if(T[mid] == i) return i;
		if(T[mid] > i) e = mid - 1;
		if(T[mid] < i) s = mid + 1;
	}
	return -1;
}
int main()
{
	build();
	int n;
	while(~scanf(" %d", &n))
	{
		if(!n) break;
		if(~Bs(n)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
