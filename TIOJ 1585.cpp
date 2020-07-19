#include <iostream>
#define Max 1010

using namespace std;

typedef struct data{
	int ptr;
} Data;

char in[Max][Max];

const char s[27] = {'\0','a','z','b','y','c','x','d','w','e','v','f','u','g','t','h','s','i','r','j','q','k','p','l','o','m','n'};

int CtoI(char c)
{
	for(int i = 0; i < 26; i++)
		if(!(s[i]^c)) return i;
}
bool cmp(Data a, Data b)
{
	int i;
	for(i = 0; in[a.ptr][i] && in[b.ptr][i]; i++)
		if(in[a.ptr][i] > in[b.ptr][i]) return 0;
	if(!in[b.ptr][i]) return 0;
	return 1;
}
int main()
{
	Data rec[Max];
	int N;
	while(~scanf(" %d", &N))
	{
		for(int i = 0; i < N; i++)
		{
			scanf(" %s", in[i]);
  			rec[i].ptr = i;
			int k;
			for(k = 0; in[i][k]; k++)
				in[i][k] = CtoI(in[i][k]);
			for(int j = 0; in[i][j]; j++) printf("%d", in[i][j]);
			printf("\n");
		}
		sort(rec, rec + N, cmp);
		for(int i = 0; i < N; i++)
		{
			for(int k = 0; in[rec[i].ptr][k]; k++)
			    printf("%c", s[in[rec[i].ptr][k]]);
			if(i != N - 1)
				printf("\n");
		}
	}
	return 0;
}
