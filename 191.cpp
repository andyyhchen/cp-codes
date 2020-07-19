#include <iostream>
#include <stdio.h>
using namespace std;
struct pt{int x, y;};
struct sg{pt p1, p2;};
int direction(pt a, pt b, pt c)
{
	return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}
bool on_line(pt a, sg b)
{
	return ((min(b.p1.x, b.p2.x) <= a.x) && (a.x <= max(b.p1.x, b.p2.x)) && (min(b.p1.y, b.p2.y) <= a.y) && (a.y <= max(b.p1.y, b.p2.y)));
}
bool intersection(sg a, sg b)
{
	int d1 = direction(a.p1, a.p2, b.p1),
		d2 = direction(a.p1, a.p2, b.p2),
		d3 = direction(b.p1, b.p2, a.p1),
		d4 = direction(b.p1, b.p2, a.p2);
	if((d1 * d2 < 0) && (d3 * d4 < 0)) return true;
	if(!d1) return on_line(b.p1, a);
	if(!d2) return on_line(b.p2, a);
	if(!d3) return on_line(a.p1, b);
	if(!d4) return on_line(a.p2, b);
	return false;
}
int main()
{
	int x[2], y[2], t;
	sg oL, sq[4];
	pt sp[4];
	freopen("tmp.txt","w",stdout);
	scanf(" %d", &t);
	while(t-- && cin>>oL.p1.x>>oL.p1.y>>oL.p2.x>>oL.p2.y>>x[0]>>y[0]>>x[1]>>y[1]){
  		sp[3].x = min(x[0], x[1]); sp[3].y = min(y[0], y[1]);
		sp[1].x = max(x[0], x[1]); sp[1].y = max(y[0], y[1]);
		sp[0].x = sp[3].x; sp[0].y = sp[1].y;
		sp[2].x = sp[1].x; sp[3].y = sp[3].y;
		if((min(x[0], x[1]) < oL.p1.x) && (oL.p1.x < max(x[0], x[1])) && (min(x[0], x[1]) < oL.p2.x) && (oL.p2.x < max(x[0], x[1])) && (min(y[0], y[1]) < oL.p1.y) && (oL.p1.y < max(y[0], y[1])) && (min(y[0], y[1]) < oL.p2.y) && (oL.p2.y < max(y[0], y[1]))){
			printf("T\n");
		}else{
			for(int i = 1; i <= 4; i++){
				sq[i - 1].p1 = sp[i - 1];
				sq[i - 1].p2 = sp[i % 4];
			}
			int flag = false;
			for(int i = 0; i < 4; i++){
				if(intersection(oL, sq[i])) flag = true;
			}
			if(flag) printf("T\n");
			else printf("F\n");
		}
	}

	return 0;
}
