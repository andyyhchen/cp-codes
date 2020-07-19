#include <iostream>
using namespace std;
int fail[100];
void failure(char pat[100])
{
	int len = strlen(pat);
	fail[0] = -1;
	int i, j = -1;
	for(i = 1; i < len; ++i){
		while(j > -1 && pat[i] != pat[j + 1]) j = fail[j];
		if(pat[i] == pat[j + 1]) ++j;
		fail[i] = j;
	}
}
void kmp(char a[100], char b[100])
{
	int lena = strlen(a), lenb = strlen(b);
	for(int i = 0, j = -1; i < lena; i++){
		while(j >= 0 && a[i] != b[j + 1]) j = fail[j];
		if(a[i] == b[j + 1]) j++;
		if(j == lenb - 1) cout << i - j + 1 << "\n";
	}
}
int main()
{
	char a[100] = "aabzabzabcz", b[100] = "abzabc";
	failure(b);
	kmp(a,b);
	return 0;
}
