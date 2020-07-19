/*
ID : andypcu2
PROG : transform
LANG : C++
*/

#include <iostream>
#include <string.h>
#define N 11

using namespace std;

typedef struct data{
	char graph[N][N];
	int size;
} data;

inline data rotate90(data in)
{
	char tmp[N][N];
	int size = in.size;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			tmp[j][size - i - 1] = in.graph[i][j];
	memcpy(in.graph, tmp, N * N);
	return in;
}


inline data reflect(data in)
{
	char tmp[N][N];
	int size = in.size;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			tmp[i][j] = in.graph[i][size - j - 1];
	memcpy(in.graph, tmp, N * N);
	return in;
}

inline bool gcmp(data in, data org)
{
	int s = in.size;
	for(int i = 0; i < s; i++)
		for(int j = 0; j < s; j++)
			if(in.graph[i][j] != org.graph[i][j]) return false;
	return true;
}
FILE *fin = fopen("transform.in", "r");
FILE *fout = fopen("transform.out", "w");
inline void input(int n, data &a)
{
	a.size = n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			fscanf(fin," %c",&a.graph[i][j]);
}
int main()
{
	int n;
	data final, org;
	while(~fscanf(fin," %d", &n))
	{
		int ans = 0;
		input(n,org); input(n,final);
			if(gcmp(rotate90(org), final))
			ans = 1;
		else if(gcmp(rotate90(rotate90(org)),final))
			ans = 2;
		else if(gcmp(rotate90(rotate90(rotate90(org))),final))
		    ans = 3;
		else if(gcmp(reflect(org), final))
		    ans = 4;
		else if(gcmp(reflect(org), final)) ans = 5;
		else if(gcmp(rotate90(reflect(org)), final)) ans = 5;
		else if(gcmp(rotate90(rotate90(reflect(org))),final)) ans = 5;
		else if(gcmp(rotate90(rotate90(rotate90(reflect(org)))),final)) ans = 5;
		else if(gcmp(org, final))ans = 6;
		else ans = 7;
		
		fprintf(fout,"%d\n",ans);
	}

	            
	return 0;
}
