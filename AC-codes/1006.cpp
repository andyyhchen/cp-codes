#include <iostream>
#include <math.h>
using namespace std;
struct bign{
	int digit[200];
	int len;
};
void bign_ini(bign &a)
{
	memset(a.digit,0,sizeof(a.digit));
	a.len = 1;
}
bool operator>=(const bign a, const bign b)
{
	int lena = a.len, lenb = b.len;
	if(lena>lenb)return true;
	if(lena<lenb) return false;
	for(int i = lena - 1; i >= 0; i--)
		if(a.digit[i]<b.digit[i]) return false;;
	return true;
}
bign operator-(const bign a, const bign b)
{
	int len = a.len;
	bign tmp; bign_ini(tmp);
	for(int i = 0; i < len; i++)
	{
		tmp.digit[i] += a.digit[i] - b.digit[i];
		if(tmp.digit[i]<0)
		{
			tmp.digit[i+1]--;
			tmp.digit[i]+=10;
		}
	}
	len+=20;
	while(tmp.digit[len]==0&&len)len--;
	tmp.len = len+1;
	return tmp;
}
bign operator*(const bign a, const bign b)
{
	int lena = a.len, lenb = b.len;
	bign tmp; bign_ini(tmp);
	for(int i = 0; i < lena; i++)
	    for(int j = 0; j < lenb; j++)
	    {
			tmp.digit[i+j] += a.digit[i] * b.digit[j];
			tmp.digit[i+j+1]+=tmp.digit[i+j]/10;
			tmp.digit[i+j]%=10;
		}
	int t_len = lena+lenb+10;
	while(t_len&&tmp.digit[t_len]==0) t_len--;
	tmp.len = t_len+1;
	return tmp;
}
bign int2bign(int n)
{
	bign tmp; bign_ini(tmp);
	int index = 0;
	if(n==0)
	{
		tmp.len = 1;
		return tmp;
	}
	while(n)
	{
		tmp.digit[index++]=n%10;
		n/=10;
	}
	tmp.len = index;
	return tmp;
}
bign operator/(const bign a, const bign b)
{
	int sub = a.len - b.len;
	bign at = a;
	bign tmp; bign_ini(tmp);
	for(int i = sub; i >= 0; i--)
	{
		for(int j = 0; j < 10; j++)
		{
			if((at>=b*int2bign(((j)*(int)(pow(10,i)+10e-9))))&&!(at>=b*int2bign(((j+1)*(int)(pow(10,i)+10e-9)))))
			{
				at = at - b*int2bign(((j)*(int)pow(10,i)));
				tmp.digit[i]=j;
			}
		}
	}
	int len = sub+10;
	while(tmp.digit[len]==0&&len) len--;
	tmp.len = len+1;
	return tmp;
}
bign getbign()
{
	char s[201];
	bign tmp; bign_ini(tmp);
	scanf(" %s", s);
	int len = strlen(s);
	for(int i = len-1; i >= 0; i--)
		tmp.digit[len-i-1]+=s[i]-'0';
	len+=10;
	while(tmp.digit[len]==0&&len) len--;
	tmp.len=len+1;
	return tmp;
}
int main()
{
	while(1)
	{
		bign in1=getbign();
		bign in2=getbign();
		bign tmp; bign_ini(tmp);
		tmp = in1/in2;
		for(int i = tmp.len-1; i >= 0; i--)
		    printf("%d",tmp.digit[i]);
		cout<<"\n";
	}
	return 0;
}
