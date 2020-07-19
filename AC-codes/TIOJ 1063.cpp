#include <iostream>
using namespace std;
struct point{
	int h, s;
};
point stack[202];
int s;
int map[202][202];
/*
5 5
1 0 0 0 0
1 1 1 1 0
1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
*/
int main()
{
	int n, m;
	while(~scanf(" %d %d", &n, &m)){
		for(int i = 0; i <= n + 1; i++){
			map[i][m + 1] = map[i][0] = -1;
		}
		for(int i = 1; i <= m; i++) map[0][i] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf(" %d", &map[i][j]);
				if(map[i][j]) map[i][j] = map[i - 1][j] + 1;
			}
		}
		point t;
		int maxs = 0, l;
		for(int i = 1; i <= n; i++){
			s = 0;
			t.s = 0;
			t.h = 0;
			stack[s++] = t;
			for(int j = 1; j <= m+1; j++){
				while(map[i][j] < stack[s - 1].h && s > 0){
					maxs = max(maxs, stack[s - 1].h * (j - stack[s - 1].s)+1);
					s--;
				}
				if(stack[s - 1].h < map[i][j]){
					t.s = j; t.h = map[i][j];
					stack[s++] = t;
				}
			}
		}
		printf("%d\n", maxs);
	}
	return 0;
}
