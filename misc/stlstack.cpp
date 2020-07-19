#include <iostream>
#include <stack>

using namespace std;

stack < int > s;

int main()
{
	for(int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	printf("%d\n\n", s.size());
	printf("%d\n\n", s.empty());
	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}
	

	system("pause");
	return 0;
}
