#include <iostream>
#include <queue>
#define Max 1000

using namespace std;

int key[Max], prev[Max], next[Max];
queue < int > fre;

void ini(void)
{
	for(int i = 0; i < Max; i++) fre.push(i);
}
	
int newNode(int in)
{
	int tmp = fre.front(); fre.pop();
	key[tmp] = in;
	prev[tmp] = next[tmp] = -1;
	return tmp;
}

void Insert(int i, int j)  //insert node(j) after ndoe(i)
{
    if(~next[i]) prev[next[i]] = j;
    next[j] = next[i];
	next[i] = j;
	prev[j] = i;
}

int Search(int root, int i)
{
	int tmp = root;
	while(~tmp)
	{
		if(key[tmp] == i) return tmp;
		tmp = next[tmp];
	}
	return -1;
}

void Delete(int root, int i) //delete node(key[i])
{
	int tmp = Search(root, i);
	if(!(~tmp)) return;
	int t = next[tmp];
	if(t != -1)
	{
		prev[t] = prev[tmp];
		next[prev[tmp]] = t;
	}
	else
	{
		next[prev[tmp]] = -1;
	}
	fre.push(tmp);
}

int main()
{
	ini();
	int root = newNode(-1);
	for(int i = 0; i < 100; i++)
		Insert(root, newNode(i));
	for(int j = 0; j < 50; j++)
	    Delete(root, j);
	int n;
	while(~scanf(" %d", &n))
	    cout << Search(root, n) << "\n";

	//system("pause");
	return 0;
}
