#include <iostream>

using namespace std;

int main()
{
	int ans[100], in;
	while(~scanf(" %d", &in))
	{
		if(in<0)
		{
			cout<<-1<<"\n";
			continue;
		}
		if(!in) cout<<0;
		int i = 0; ans[0] = 0;
		while(in)
		{
			ans[i++] = in % 8;
			in /= 8;
		}
		
		for(int j = i - 1; j >= 0; j--)
		{
			cout<<ans[j];
		}
		cout<<"\n";
	}
	return 0;
}
