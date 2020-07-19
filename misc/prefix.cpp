#include <iostream>

using namespace std;

int main()
{
	char filename[10],input;
	while(printf("請輸入檔案名稱,輸入-1結束:")&&gets(filename+1))
	{
		if(filename[1]=='-'&&filename[2]=='1')break;
  		filename[0]='Q';
		strcat(filename,".cpp");
		FILE *source=fopen(filename,"r");
		FILE *tmp=fopen("copy.tmp","w");
		while(~fscanf(source,"%c",&input))fprintf(tmp,"%c",input);
		fclose(source);fclose(tmp);
		int i=0;
		source=fopen(filename,"w");
		while(filename[i++]!='Q');
		fprintf(source,"/*\nProblem: ");
		fprintf(source,"%s\n",filename+i-1);
		fprintf(source,"Author: andyisman\n");
		time_t theTime;
	    time( &theTime );
	    tm *t = localtime( &theTime );
	    fprintf(source,"Complete time: %s*/\n\n",asctime(t));
	    tmp=fopen("copy.tmp","r");
	    while(~fscanf(tmp,"%c",&input)){fprintf(source,"%c",input);}
	    fclose(tmp);fclose(source);
	    remove("copy.tmp");
	    printf("Complete!\n");
	}
	return 0;
}
