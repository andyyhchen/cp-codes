#include <iostream>
#include <vector>
using namespace std;
int pos[100001], lis[100001], g[100001];
int main()
{
	int n1, n2;
	int a[100001], b[100001], ea[100001], eb[100001];
	vector <int> c ,d;
	while(cin >> n1){
		c.clear();d.clear();
		memset(ea,0,sizeof(ea));
		memset(ea,0,sizeof(ea));
		for(int i = 0; i < n1; i++){
			cin >> a[i];
			ea[a[i]] = 1;
		}
		cin >> n2;
		int ans =  0;
		for(int i = 0; i < n2; i++){
			cin >> b[i];
			eb[b[i]] = 1;
		}
		for(int i = 0; i < n1; i++){
			if(!eb[a[i]]) ans++;
			else c.push_back(a[i]);
		}
		for(int i = 0; i < n2; i++){
			if(!ea[b[i]]) ans++;
			else d.push_back(b[i]);
		}
		for(int i = c.size()-1; i >= 0; i--)pos[c[i]] = i;
		for(int i = d.size()-1; i >= 0; i--)lis[i] = pos[d[i]];
		fill(g, g + 100001, 2147483647);
		for(int i = 0; i < d.size(); i++){
			*lower_bound(g,g+100001,lis[i]) = lis[i];
		}
		int a = lower_bound(g,g+100001,9999999) - g;
		ans += (d.size() - a)*2;
		cout << ans << "\n";
	}

	return 0;
}
