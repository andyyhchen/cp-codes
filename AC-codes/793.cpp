#include <iostream>
using namespace std;
int set[1010];
bool used[1010];
int findset(int a)
{
	used[a] = true;
	int p = a, q = a;
	while(a!=set[a]) a = set[a];
	while(p!=set[p])
	{
		used[p] = true;
		q = p;
		p = set[p];
		set[q] = a;
	}
}
void disjoint(int a, int b)
{
	int ga = findset(a), gb = findset(b);
	if(ga!=gb) set[gb] = ga;
}
int main()
{
	int a, b, t, n, flag = 0;
	char c, s[10];
	cin>>t;
	while(t--)
	{
        if ( flag ) puts("");
        else flag=1;
        cin>>n;
		for(int i = 0; i <= n; i++)
		{
			set[i] = i;
			used[i] = false;
		}
		while(getchar()!='\n');
		int un = 0, cn = 0;
		while ( gets(s)&&*s )
		{
            sscanf(s,"%c %d %d",&c,&a,&b);
            if ( c=='q' )
            {
				if(used[a]&&used[b]) cn++;
				else un++;
			}
            else disjoint(a,b);
		}
		cout<<un<<","<<cn<<"\n";
	}
	return 0;
}
