#include <stdio.h>
#define Max 4

bool col[Max + 1][Max + 1], row[Max + 1][Max + 1], block[Max / 2][Max / 2][Max + 1], flag;
int sol[Max + 1][Max + 1];

void ini()
{
	for(int i = 0; i < Max; i++)
	{
		for(int j = 0; j < Max; j++)
		{
			if(sol[i][j])
				col[i][sol[i][j]] = row[j][sol[i][j]] = block[i / 2][j / 2][sol[i][j]] = true;
		}
	}
}

int c = 0;
void DFSsearch(int t)
{
	int x = t / Max, y = t % Max;
	if(t > 15)
	{
        c++;
		for(int i = 0; i < Max && flag; i++)
		{
			for(int j = 0; j < Max; j++)
			{
				printf("%d",sol[i][j]);
			}
			printf("\n");
		}
		if(flag)printf("\n"); 
		flag = false;
		return;
	}
	if(sol[x][y])
	{
		DFSsearch(t+1);
		return;
	}
	for(int i = 1; i <= Max; i++)
	{
		if(!col[x][i] && !row[y][i] && !block[x / 2][y / 2][i])
		{
            col[x][i] = row[y][i] = block[x / 2][y / 2][i] = true;
            sol[x][y] = i;
            DFSsearch(t+1);
            sol[x][y] = 0;
            col[x][i] = row[y][i] = block[x / 2][y / 2][i] = false;
		}
	}
}
int main()
{
	c = 0; flag = true;
	for(int i = 0; i < Max; i++)
	{
		for(int j = 0; j < Max; j++)
		{
			scanf(" %d", &sol[i][j]);
			if(sol[i][j]>4 || sol[i][j] < 0) flag = false;
		}
	}
	if(flag)
	{
		ini();
		DFSsearch(0);
	}
	if(c) printf("We have %d way(s) to solve it!!\n", c);
	else printf("I can not solve!!\n");
	return 0;
}
