#include <iostream>
#define Max 7501

using namespace std;

int dp[21][Max * 2];

int main()
{
	int nC, nG, C[21], G[21];

	while(~scanf(" %d %d", &nC, &nG)){

		for(int i = 0; i < nC; i++){
			scanf(" %d", &C[i]);
		}
		for(int i = 0; i < nG; i++){
			scanf(" %d", &G[i]);
		}

		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < nC; i++){
			dp[0][Max + C[i] * G[0]]++;
		}

		for(int i = 1; i < nG; i++){
            for(int k = -Max; k <= Max; k++){
				int s = 0;
				for(int j = 0; j < nC; j++){
					int p = Max + k - C[j] * G[i];
					if(p >= 0){
						s += dp[i - 1][p];
					}
				}
				dp[i][Max + k] = s;
			}
		}
		printf("%d\n", dp[nG - 1][Max]);
		
	}

	return 0;
}
