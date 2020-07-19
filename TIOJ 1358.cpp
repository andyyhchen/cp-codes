#include <iostream>
using namespace std;
int main()
{
	int n, ans;
	while(~scanf(" %d", &n))
	{
		ans = 0; n--;
		while(n)
		{
			ans+=n;
			n/=2;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
