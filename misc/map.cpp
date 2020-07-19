#include <iostream>
#include <map>

using namespace std;

map <char *, char *> a;

int main()
{
	a.clear();
	for(int i = 0; i < 1000; i++)
	{
		a.insert(pair<char *, char *>("70", "bill"));
	}
	
	//out << a.size() << endl;
	
	//for(int j = 0; j < 100; j++)
	//	a.erase(a.find(100 + j));
	//a.erase(a.find(39));

	cout << a.count("70") << endl;
	cout << a.end() -> first << endl;
		
	//cout << a.size() << endl;
	//cout << a[300] << endl;

	system("pause");
	
	return 0;
}
