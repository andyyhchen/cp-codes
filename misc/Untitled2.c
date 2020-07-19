#include <stdio.h>
int s[16]={0x111f,0x222f,0x444f,0x888f,0x11f1,0x22f2,0x44f4,0x88f8,
           0x1f11,0x2f22,0x4f44,0x8f88,0xf111,0xf222,0xf444,0xf888};
int main()
{char c;int i,n,j;
n=i=j=0;
while((c=getchar())!=EOF)
if(c!=10)if(c=='+')n^=s[i++];else ++i;
for(i=0;i<16;++i)if(n&(1<<i))++j;printf("%d\n",j);
for(i=0;i<16;++i)if(n&(1<<i))printf("%d %d\n",i/4+1,i%4+1);}
