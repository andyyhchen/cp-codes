#include <iostream>
#define Max 10000
#define fill 10000
using namespace std;

typedef struct bigint{
	int digit[Max];
	int len;
} bigint;

void bigint_ini(bigint &a)
{
	a.len = 0;
	memset(a.digit, 0, sizeof(a.digit));
}

bigint int2bigint(int in)
{
	bigint tmp; bigint_ini(tmp);
	int i = 0;
	if(!in)
	{
		tmp.len = 1;
		tmp.digit[0]=0;
		return tmp;
	}
	while(in)
	{
		tmp.digit[i++] = in % fill;
		in /= fill;
	}
	tmp.len = i;
	return tmp;
}

bigint str2bigint(char s[Max * 4])
{
	bigint tmp; bigint_ini(tmp);
	int len = strlen(s), n = 0;
	const int a[4] = {1, 10, 100, 1000};
	for(int i = len - 1; i >= 0;)
	{
		for(int j = 0; j < 4 && i+1; j++)
			tmp.digit[n] += (s[i--] - '0') * a[j];
		n++;
	}
	while(tmp.digit[n]!=0&&n) n--;
	tmp.len = n;
	return tmp;
}

void bigint2str(bigint a)
{

}


bool operator>(bigint a, bigint b)  // a > b
{
	int lena = a.len, lenb = b.len;
	if(lena > lenb) return true;
	else if(lena < lenb) return false;
	else
		for(int i = lena; i >= 0; i--)
			if(a.digit[i] > b.digit[i]) return true;
	return false;
}

bool operator<(bigint a, bigint b)  // a < b
{
	int lena = a.len, lenb = b.len;
	if(lena > lenb) return false;
	else if(lena < lenb) return true;
	else
		for(int i = lena; i >= 0; i--)
			if(a.digit[i] > b.digit[i]) return false;
	return true;
}

bool operator==(bigint a, bigint b)  // a == b
{
	int lena = a.len, lenb = b.len;
	if(lena > lenb) return false;
	else if(lena < lenb) return false;
	else
		for(int i = lena; i >= 0; i--)
			if(a.digit[i] > b.digit[i]) return false;
	return true;
}

bigint operator+(const bigint a, const bigint b)
{
	int lena = a.len, lenb = b.len;
	bigint tmp; bigint_ini(tmp);
	for(int i = 0; i < max(lena, lenb); i++)
	{
		tmp.digit[i] = a.digit[i] + b.digit[i];
		tmp.digit[i + 1] = tmp.digit[i] / fill;
		tmp.digit[i] %= fill;
	}
	int i = max(lena, lenb) + 10;
	while(tmp.digit[i]==0) i--;
	tmp.len = i + 1;
	return tmp;
}

bigint operator-(const bigint a, const bigint b)
{
	bool flag = false;
    int lena = a.len, lenb = b.len;
	bigint tmp; bigint_ini(tmp);
	if(a > b)
	{
		for(int i = 0; i < lena; i++)
		{
			tmp.digit[i] = a.digit[i] - b.digit[i];
			if(tmp.digit[i]<0)
			{
				tmp.digit[i+1]--;
				tmp.digit[i]+=fill;
			}
		}
	}
	else
	{
		flag = true;
		for(int i = 0; i < lenb; i++)
		{
			tmp.digit[i] = b.digit[i] - a.digit[i];
			if(tmp.digit[i]<0)
			{
				tmp.digit[i+1]--;
				tmp.digit[i]+=fill;
			}
		}
	}
	int i = max(lena, lenb)+ 10;
	while(tmp.digit[i]==0)i--;
	if(flag) tmp.digit[i] = -tmp.digit[i];
	if(i<0)i=0;
	tmp.len = i + 1;
	return tmp;
}

bigint operator*(const bigint a, const bigint b)
{
    int lena = a.len, lenb = b.len;
	bigint tmp; bigint_ini(tmp);
	for(int i = 0; i < lena; i++)
	{
		for(int j = 0; j < lenb; j++)
		{
			tmp.digit[i+j] = a.digit[i]*b.digit[j];
			tmp.digit[i+j+1]+=tmp.digit[i]/fill;
			tmp.digit[i]%=fill;
		}
	}
    int i = lena + lenb + 10;
    while(tmp.digit[i]==0)i--;
    if(i<0)i=0;
    tmp.len = i + 1;
    return tmp;
}

int main()
{
	int i;
	char in[Max];
	while(scanf(" %d",&i))
	{
        bigint tmp; bigint_ini(tmp);
	bigint a = int2bigint(i);
	a = a * a;
	for(int i= a.len - 1; i >= 0; i--)
	{
		printf("%04d",a.digit[i]);
	}
	cout<<"\n";
}

	system("pause");
	return 0;
}
