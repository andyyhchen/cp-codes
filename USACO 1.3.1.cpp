/*
ID : andypcu2
PROG : milk
LANG : C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct farmer{
	int price, num;
} farmer;

bool cmp(farmer a, farmer b)
{
	return a.price < b.price;
}

int main()
{
	FILE *fin = fopen("milk.in","r");
	FILE *fout = fopen("milk.out","w");
	int n, m;
	farmer t_f;
	vector <farmer> in;
	while(~fscanf(fin," %d %d", &n, &m))
	{
		in.clear();
		while(m--)
		{
			fscanf(fin," %d %d", &t_f.price, &t_f.num);
			in.push_back(t_f);
		}
		sort(in.begin(), in.end(), cmp);
		int cost = 0;
		int size = in.size();
		int total_w = n;
		for(int i = 0; i < size; i++)
		{
			if(total_w >= in[i].num)
			{
				cost+=in[i].price * in[i].num;
				total_w -= in[i].num;
			}
			else
			{
				cost += in[i].price * total_w;
				break;
			}
		}
		fprintf(fout,"%d\n",cost);
	}
	return 0;
}
