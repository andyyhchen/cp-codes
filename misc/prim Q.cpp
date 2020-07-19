#include <iostream>
#include <queue>
#include <vector>
#define Edge pair <int,int>
#define Max 3

using namespace std;

int map[Max][Max];

void prim()
{
    priority_queue <Edge,vector<Edge> > Q;  // pair(weigh, vertex)
	int T[Max]={0};
	Q.push(make_pair(-1,0));
	while(!Q.empty())
	{
		Edge tmp = Q.top();Q.pop();
		T[tmp.second]=-tmp.first;
		for(int i = 0; i < Max; i++)
			if(map[tmp.second][i]&&!T[i])
				Q.push(make_pair(-map[tmp.second][i],i));
	}
	int ans = 0;
	for(int i = 0; i < Max; i++) ans += T[i];
	cout << ans << "\n";
}

int main()
{

	prim();
	system("pause");
	return 0;
}
