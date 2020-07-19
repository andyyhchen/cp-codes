#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	while(~scanf(" %d %d", &a, &b))
	{
		int ans = 0;
		if(a < b) swap(a,b);
		while(b)
		{
			ans += a / b;
			a %= b;
			swap(a, b);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
