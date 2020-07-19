// constructing priority queues
#include <iostream>
#include <queue>
using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return 1;
    else return 0;
  }
};

bool cmp(int a, int b)
{
	if(a < b) return 1;
	return 0;
}
int main ()
{
    priority_queue< int, vector<int>, mycomparison > Q;

	for(int i = 0; i < 100; i++)
	{
		Q.push(i);
	}
	printf("%d ", Q.top());

	system("pause");
  	return 0;
}
