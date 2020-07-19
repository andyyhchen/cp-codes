#include <iostream>
#include <queue>

using namespace std;

queue < int > a;

int main()
{
	bool flag = false;
	cout << flag << "\n";
	for(int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	
	cout << a.size() << endl;
	
	for(int i = 0; i < 199; i++)
 	{
		if(a.empty()) break;
		cout << a.front() << "\n";
		a.pop();
	}
	
	cout << "Size: " << a.size() << "\n";

	system("pause");
	
	return 0;
}
