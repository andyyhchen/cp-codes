#include <iostream>
using namespace std;
struct bign{
	int digit[100];
	int len;
};
void ini(bign &a)
{
	memset(a.digit,0,sizeof(a.digit));
	a.len = 1;
}
bign operator+(const bign a, const bign b)
{
	bign tmp; ini(tmp);
	int len = max(a.len, b.len);
	for(int i = 0; i < len; i++)
	{
		tmp.digit[i] += a.digit[i] + b.digit[i];
		tmp.digit[i+1]+=tmp.digit[i]/100000000;
		tmp.digit[i]%=100000000;
	}
	len+=10;
	while(tmp.digit[len]==0) len--;
	tmp.len = len+1;
	return tmp;
}
bign way[1001];
int main()
{
	way[0].digit[0] = 1; way[0].len = 1;
	way[1].digit[0] = 2; way[1].len = 1;
	way[2].digit[0] = 5; way[2].len = 1;
	for(int i = 3; i < 1001; i++)
	    way[i] = way[i - 1] + way[i - 1] + way[i - 2] + way[i - 3];
	int n;
	while(cin>>n)
	{
		printf("%d", way[n].digit[way[n].len-1]);
		for(int i = way[n].len - 2; i >= 0; i--)
		    printf("%.8d", way[n].digit[i]);
		puts("");
	}
	return 0;
}
