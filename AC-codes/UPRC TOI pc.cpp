#include <iostream>
using namespace std;
int s[100001], w[100001];
int main()
{
	int n, m;
	while(cin>>n>>m)
	{
		for(int i = 0; i < n; i++) scanf("%d", s+i);
		for(int j = 0; j < m; j++) scanf("%d", w+j);
		if(n<=m)
		{
			sort(s,s+n);
			sort(w,w+m);
			int wi = -1, i;
			long long int ans = 0;
			for(i = 0; i < n; i++)
			{
				while(wi<m&&s[i]>=w[++wi]);
				if(wi==m) break;
				ans+=(long long int)w[wi];
			}

			if(i!=n) puts("We Lose.");
			else printf("%I64d\n",ans);
		}
		else puts("We Lose.");
	}

	return 0;
}
