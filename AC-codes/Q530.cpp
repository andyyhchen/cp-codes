#include <iostream>

using namespace std;
int f(int i)
{
	if(!i) return 1;
	return i * f(i-1);
}

int main()
{

	system("pause");
	return 0;
}
