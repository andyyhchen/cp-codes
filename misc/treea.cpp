#include <iostream>
#define Max 10

using namespace std;

int tree[Max];

void preorder(int i)
{
	if(i < Max && tree[i])
	{
		printf("%d ", i);
		preorder(i * 2);
		preorder(i * 2 + 1);
	}
	return;
}

void inorder(int i)
{
	if(i < Max)
	{
		inorder(i * 2);
		printf("%d ", i);
		inorder(i * 2 + 1);
	}
	return;
}

void postorder(int i)
{
	if(i < Max)
	{
		postorder(i * 2);
		postorder(i * 2 + 1);
		printf("%d ", i);
	}
	return;
}



int main()
{
	for(int i = 0; i < Max; i++)
		tree[i] = i;
	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);
	cout << "\n";
	

	system("pause");
	return 0;
}
