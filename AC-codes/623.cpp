#include <iostream>
using namespace std;
struct bign{
	int digit[800];
	int len;
};
void bign_ini(bign &a)
{
	a.len = 1;
	for(int i = 0; i < 800; i++) a.digit[i] = 0;
}
bign operator*(const bign a, const bign b)
{
	int lena = a.len, lenb = b.len;
	bign tmp; bign_ini(tmp);
	for(int i = 0; i < lena; i++)
	    for(int j = 0; j < lenb; j++)
	    {
			tmp.digit[i+j] += a.digit[i] * b.digit[j];
			tmp.digit[i+j+1]+=tmp.digit[i+j]/10000;
			tmp.digit[i+j]%=10000;
		}
	int t_len = lena+lenb+10;
	while(t_len&&tmp.digit[t_len]==0) t_len--;
	tmp.len = t_len+1;
	return tmp;
}
bign int2bign(int a)
{
    bign tmp; bign_ini(tmp);
	tmp.digit[0] = a;
	tmp.len = 1;
	return tmp;
}
void print(bign a, int n)
{
	cout<<n<<"!\n";
	int len = a.len;
	const int m[4] = {1000,100,10,1};
	printf("%d",a.digit[len-1]);
	for(int i = len-2; i >= 0; i--)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%d", a.digit[i] / m[j]);
			a.digit[i]%=m[j];
		}
	}
	puts("");
}
bign table[1010];
int main()
{
	table[0].digit[0] = 1;
	table[0].len = 1;
	for(int i = 1; i < 1001; i++)
		table[i] = int2bign(i) * table[i-1];
	int n;
	while(cin>>n)
		print(table[n],n);
	return 0;
}
