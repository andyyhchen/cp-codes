#include <iostream>

using namespace std;

int v(char c)
{
	const char s[7] = {'I','V','X','L','C','D','M'};
	const int a[7] = {1, 5, 10, 50, 100, 500, 1000};
	for(int i =0; i < 7; i++)
		if(s[i] == c) return a[i];
	return 0;
}

int RtoI(char s[4000])
{
	int ans = 0;
	for(int i = 0; s[i]; i++)
	{
		if(v(s[i]) < v(s[i+1])) ans -= v(s[i]);
		else ans+=v(s[i]);
	}
	return ans;
}

void ItoR(int in)
{
	if(!in) printf("ZERO");
	const char s[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	const int a[13]     = {1000, 900, 500,  400, 100,  90,   50,  40,  10,    9,   5,    4,    1};
	for(int i = 0; i < 13; i++)
	{
		int t = in / a[i];
		for(int j = 0; j < t; j++) printf("%s", s[i]);
		in -= t * a[i];
	}
	printf("\n");
}
int main()
{
	char s1[4000], s2[4000];
	while(scanf(" %s %s", s1, s2)==2)
	{
		int ans = abs(RtoI(s1) - RtoI(s2));
		ItoR(ans);
	}
	return 0;
}
