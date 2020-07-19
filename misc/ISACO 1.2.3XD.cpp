/*
ID : andypcu2
PROG : namenum
LANG : C++
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int code[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	
	FILE *dict = fopen("dict.txt","r");
	FILE *fin = fopen("namenum.in","r");
	FILE *fout = fopen("namenum.out","w");
	char in[13], data[13];
	int len; bool flag = false;
	fscanf(fin," %s",in);
	while(~fscanf(dict, " %s", data))
	{
		flag = false;
		len = strlen(in);
		if(len != strlen(data)) continue;
		for(int i = 0; i < len; i++)
			if(in[i]-'0'!=code[data[i]-'A']) flag = true;
		if(!flag) fprintf(fout,"%s\n",data);
	}
	if(flag) printf("NONE\n");
	return 0;
}
