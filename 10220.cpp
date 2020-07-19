#include <iostream>
using namespace std;
struct bign{
	int digit[800];
	int len;
};
void bign_ini(bign &a)
{
	memset(a.digit,0,sizeof(a.digit));
	a.len = 1;
}
bign operator*(const bign a, const bign b)
{
	int lena = a.len, lenb = b.len;
	bign tmp; bign_ini(tmp);
	for(int i = 0; i < lena; i++)
	{
		for(int j = 0; j < lenb; j++)
		{
			tmp.digit[i+j] += a.digit[i] * b.digit[j];
			tmp.digit[i+j+1] += tmp.digit[i+j]/10000;
			tmp.digit[i+j] %= 10000;
		}
	}
	int t_len = lena+lenb+10;
	while(tmp.digit[t_len]==0) t_len--;
	tmp.len = t_len+1;
	return tmp;
}
bign int2bign(int n)
{
	bign tmp; bign_ini(tmp);
	int index = 0;
	while(n)
	{
		tmp.digit[index++]=n%10000;
		n/=10000;
	}
	tmp.len = index;
	return tmp;
}
int count(bign a)
{
	int len = a.len, ans = 0;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			ans+=a.digit[i]%10;
			a.digit[i]/=10;
		}
	}
	return ans;
}
bign table[1001];
int main()
{
	table[0].digit[0] = 1;
	table[0].len = 1;
	for(int i = 1; i < 1001; i++)
	    table[i] = table[i-1]*int2bign(i);
	int n;
	while(cin>>n)
		cout<<count(table[n])<<"\n";
	return 0;
}
