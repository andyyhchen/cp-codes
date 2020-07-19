#include<iostream>
#include<vector>
using namespace std;

vector<int> a;

int main()
{
    a.clear();
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
	int *p = a.begin();
    a.insert(a.begin()+2,3);
	cout<<a.size()<<endl;
	
	for(int i=0;i<5;i++)cout<<a[i]<<endl;
	
	system("pause");
	return 0;
}
