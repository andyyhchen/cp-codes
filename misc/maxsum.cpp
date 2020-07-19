#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
typedef struct node{
	int s;
	int e;
} NODE;
NODE tmp;
vector<NODE> R;
int main()
{
	int a[100], max = 0, sum = 0, N, i, s = 0, e = 0, stmp = 0, len, j;
	while(~scanf(" %d", &N))
	{
		stmp = max = sum = 0;
		R.clear();
		for(i = 0; i < N; i++) scanf(" %d", &a[i]);
		for(i = 0; i < N; i++)
		{
			sum += a[i];
			if(sum < 0) {sum = 0; stmp = i + 1;}
			if(sum == max)
			{
				max = sum;
				tmp.s = stmp;
				tmp.e = i + 1;
				R.push_back(tmp);
			}
			if(sum > max)
			{
				R.clear();
                max = sum;
				tmp.s = stmp;
				tmp.e = i + 1;
				R.push_back(tmp);
			}
		}
		len = R.size();
		for(i = 0; i < len; i++)
		{
			tmp = R[i];
			for(j = tmp.s; j < tmp.e; j++)
			    printf("%d ", a[j]);
			printf("\n");
		}
	}

	system("pause");
	return 0;
}
