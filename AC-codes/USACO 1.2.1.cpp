/*
ID: andypcu2
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct f{
	int s, e;
} farmer;

bool operator<(const farmer a, const farmer b)
{
	return a.s < b.s;
}
int main()
{
	freopen("milk2.in", "r", stdin); freopen("milk2.out", "w", stdout);
	vector <farmer> time;
	farmer t_farmer;
	int n;
	time.clear();
	scanf(" %d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf(" %d %d", &t_farmer.s, &t_farmer.e);
		time.push_back(t_farmer);
	}
	sort(time.begin(), time.end());
	int t_size = time.size();
	int prevstart, prevend;
	int ansIdle = 0, ansWork = 0;
	prevstart = time[0].s; prevend = time[0].e;
	ansIdle = 0; ansWork = prevend- prevstart;
	for(int i = 1; i < t_size; i++)
	{
		if(prevend >= time[i].s)
			prevend = max(time[i].e, prevend);
		else
		{
			ansWork = max(prevend - prevstart, ansWork);
			ansIdle = max(time[i].s - prevend, ansIdle);
			prevstart = time[i].s; prevend = time[i].e;
		}
	
	}
	cout<<ansWork<<" "<<ansIdle<<"\n";
	return 0;
}
