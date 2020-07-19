#include<stdio.h>
int px, py, ans = 0;
void divide(int cx, int cy, int len)
{
	int temp;
	temp = len / 2;
	if(len == 0)
		return;
		
	if( ( ( cx + len ) >= px && ( cx - len ) <= px ) && ( ( cy - len ) <= py && ( cy + len ) >= py ) )
	    ans++;
	divide(cx + len, cy + len, temp);
	divide(cx - len, cy + len, temp);
	divide(cx + len, cy - len, temp);
	divide(cx - len, cy - len, temp);
	return;
}
int main()
{
	int in;
	while( ~ scanf("%d %d %d", &in, &px, &py) )
	{
		ans = 0;
		if( ! ( in || px || py ) )
		    break;
		divide(1024, 1024, in);
		printf("%3d\n", ans);
	}
	return 0;
}
