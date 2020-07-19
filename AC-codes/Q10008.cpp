#include <iostream>
#define Max 10000

using namespace std;

typedef struct r{
	int t;
	char c;
}rec;

bool operator<(const rec &a, const rec &b)
{
	return a.t*Max-a.c>b.t*Max-b.c;
}

int main()
{
	int n;
	char in[Max],trash;
	rec R[27];
	while(~scanf(" %d",&n))
	{
        scanf("%c",&trash);
        for(int i=0;i<27;i++) R[i].c='A'+i+(R[i].t=0);
		while(n--&&gets(in))
			for(int i=0;in[i];i++) R[toupper(in[i])-'A'].t++;
		sort(R,R+27);
		for(int i=0;i<27;i++)
			if(R[i].t) printf("%c %d\n",R[i].c,R[i].t);
	}
	return 0;
}
