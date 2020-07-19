#include <iostream>
#define Max 1000000000

using namespace std;

typedef struct matrix{long long int x1, x2, x3, x4;} M;

int main()
{
  M t[31];
  t[0].x1=0; t[0].x2=1; t[0].x3=1; t[0].x4=1;
  for(int i = 1; i < 31; i++)
  {
    t[i].x1 = ((t[i-1].x1*t[i-1].x1)%Max+(t[i-1].x2*t[i-1].x3)%Max)%Max;
    t[i].x2 = ((t[i-1].x1*t[i-1].x2)%Max+(t[i-1].x2*t[i-1].x4)%Max)%Max;
    t[i].x3 = ((t[i-1].x3*t[i-1].x1)%Max+(t[i-1].x4*t[i-1].x3)%Max)%Max;
    t[i].x4 = ((t[i-1].x3*t[i-1].x2)%Max+(t[i-1].x4*t[i-1].x4)%Max)%Max;
  }

  int T, i, in;
  while(~scanf(" %d", &T))
  while(T--)
  {
    scanf(" %d", &in);
    M s,tmp;s.x1=1;s.x2=0;s.x3=0;s.x4=1;
    i = 0;
    while(in)
    {
		tmp.x1=s.x1;tmp.x2=s.x2;tmp.x3=s.x3;tmp.x4=s.x4;
		if(in%2)
		{
            s.x1 = ((tmp.x1*t[i].x1)%Max+(tmp.x2*t[i].x3)%Max)%Max;
    		s.x2 = ((tmp.x1*t[i].x2)%Max+(tmp.x2*t[i].x4)%Max)%Max;
    		s.x3 = ((tmp.x3*t[i].x1)%Max+(tmp.x4*t[i].x3)%Max)%Max;
    		s.x4 = ((tmp.x3*t[i].x2)%Max+(tmp.x4*t[i].x4)%Max)%Max;
		}
		i++;in>>=1;
	}
	printf("%I64d\n", (s.x1 + s.x3)%Max);
  }
}
