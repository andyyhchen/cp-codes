#include <iostream>
#include <stack>
#define Max 101

using namespace std;

stack <int> start;
stack <int> end;

int main()
{
	char in[Max][Max];
	int len, current, sum[Max];
 
	while(scanf(" %s", in[0]))
	{
        memset(sum, 0, sizeof(sum));
        
		len = strlen(in);
		
		for(int i = 1; i < len; i++) scanf(" %s", in[i]);
	
		for(int i = 0; i < len; i++)
		{
			for(int j = 0; j < len; j++)
			{
				if(in[i][j]) sum[j]++;
				else sum[j] = 0;
			}
			
			current = sum[0];
			for(int k = 0; k < len; k++)
			{
				if(sum[k] > current)
				{
					current = sum[k];
					start.push(k);
					end.push(k - 1);
				}
				else if(sum[k] < current)
				{
					current = sum[k];
				}
			}
		}

		
	}

	system("pause");
	return 0;
}
