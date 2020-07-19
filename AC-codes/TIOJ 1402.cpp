#include<iostream>
#include<queue>
#define Max 510
using namespace std;
typedef struct point{
	int h, i, j;
} point;

bool operator<(const point a, const point b)
{
	return a.h > b.h;
}

int M, N, map[Max][Max];
bool visit[Max][Max];
priority_queue<point> Q;

long long int floodfill(void)
{
	long long int ans = 0;
	point t_point;
	const int di[4] = {1,-1,0,0};
	const int dj[4] = {0,0,1,-1};
	while(!Q.empty())
	{
		t_point = Q.top(); Q.pop();
		long long int i = t_point.i, j = t_point.j, h = t_point.h;
		for(int k = 0; k < 4; k++)
		{
			if(i+di[k]<M&&0<=i+di[k]&&j+dj[k]<N&&0<=j+dj[k]&&!visit[i+di[k]][j+dj[k]])
			{
				visit[i+di[k]][j+dj[k]] = true;
				if(map[i+di[k]][j+dj[k]]<h)
				{
					ans+=(long long int)(h-map[i+di[k]][j+dj[k]]);
					t_point.h = h;
				}
				else
                     t_point.h = map[i+di[k]][j+dj[k]];
				t_point.i = i+di[k]; t_point.j = j+dj[k];
				Q.push(t_point);
			}
		}
	}
	return ans;
}

int main()
{
	while(~scanf(" %d %d", &M, &N))
	{
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
			    visit[i][j] = 0;
		while(!Q.empty()) Q.pop();
		point t_point;
		for(int i = 0; i < M; i++)
			for(int j = 0; j < N; j++)
			{
				scanf(" %d", &map[i][j]);
				if(!i||!j||i==M-1||j==N-1&&!visit[i][j])
				{
					visit[i][j] = true;
					t_point.i = i; t_point.j = j; t_point.h = map[i][j];
					Q.push(t_point);
				}
			}
		printf("%I64d\n",floodfill());
	}

}
