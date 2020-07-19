#include <iostream>
#include <queue>

using namespace std;

typedef struct data{
	int len;
	char s[6];
}Data;
Data tmp[27];
char rec[83700][6];
int c = 0;
void ini()
{
	for(int i = 0; i < 27; i++)
	{
		tmp[i].len = 0;
		for(int j = 0; j < 6; j++) tmp[i].s[j] = 0;
	}
}
void bfs()
{
	ini();
	queue <Data> Q; Data t_data, temp;
	for(int i = 'a'; i <= 'z'; i++)
	{
		t_data.s[0] = i;
		t_data.len = 0;
        Q.push(t_data);
	}
	while(!Q.empty())
	{
		t_data = Q.front();Q.pop();
		if(t_data.len > 4) break;
		int l = t_data.len; t_data.len++;
		for(int j = t_data.s[l]+1; j <= 'z'; j++)
		{
			t_data.s[l+1] = j;
			Q.push(t_data);
		}
	}
}

int main()
{
	bfs();
	cout<<c;
	while(1);
}
