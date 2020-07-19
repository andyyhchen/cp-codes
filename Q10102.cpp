#include <iostream>
#include <queue>
#include <vector>
#define f(x,y) (x)*Max+(y)
#define Max 101

using namespace std;

char map[Max][Max][2];
int M;
vector <int> one;
int bfs()
{
    int max = 0,t=0;
	int s = one.size();
	for(int i = 0; i < s; i++)
	{
		queue<int> Q; Q.push(one[i]);
		while(!Q.empty())
		{
			int x = Q.front() / Max, y = Q.front() % Max;Q.pop();
			if(map[x][y][0]==3)
			{
				t = map[x][y][1];
				break;
			}
			if(0<=x-1&&!map[x-1][y][1])
			{
				Q.push(f(x-1,y));
				map[x-1][y][1]=map[x][y][1]+1;
			}
			if(x+1<M&&!map[x+1][y][1])
			{
				Q.push(f(x+1,y));
				map[x+1][y][1]=map[x][y][1]+1;
			}
			if(0<=y-1&&!map[x][y-1][1])
			{
				Q.push(f(x,y-1));
				map[x][y-1][1]=map[x][y][1]+1;
			}
			if(y+1<M&&!map[x][y+1][1])
			{
				Q.push(f(x,y+1));
				map[x][y+1][1]=map[x][y][1]+1;
			}
		}
		if(t>max)max=t;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < M; j++) map[i][j][1]=0;
	}
	return max;
}

int main()
{
	char in[Max];
	while(~scanf(" %d",&M))
	{
		one.clear();
		memset(map,0,sizeof(map));
		for(int i=0;i<M;i++)
		{
			scanf(" %s",in);
			for(int j = 0; in[j]; j++)
			{
				map[i][j][0]=in[j]-'0';
				if(map[i][j][0]==1)one.push_back(f(i,j));
			}
		}
		printf("%d\n",bfs());
	}
	return 0;
}
