#include <iostream>
using namespace std;
int p[3001][2];
int main()
{
	int n, x, y;
	while(scanf(" %d", &n) && n){
		for(int i = 0; i < n; i++){
			scanf(" %d %d", &p[i][0], &p[i][1]);
		}
		int max = 0, a, b, t;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				x = abs(p[i][0] - p[j][0]);
				y = abs(p[i][1] - p[j][1]);
				t = x * x + y * y;
				if(t > max){
					a = i;
					b = j;
					max = t;
				}
			}
		}
		printf("%d %d\n", a, b);
	}

	return 0;
}
