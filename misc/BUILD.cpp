#include <iostream>
#define Max 13
using namespace std;

int preorder[Max]={1,3,5,8,6,4,7,10,12,13,2,11,9}, inorder[Max] = {8,5,6,3,4,1,12,10,13,7,11,2,9}, tree[Max+1];

int search(int s, int e, int target)
{
	for(int i = s; i <= e; i++)
	{
		if(inorder[i] == target) return i;
	}
	return -1;
}

void buildtree(int Li, int Ri, int Lp, int Rp, int root)  //Li :left inorder  and so on...
{
	if(Li > Ri) return;
	int tmp = search(Li, Ri, preorder[Lp]);
	int leftnum = tmp - Li + 1;
	tree[root] = inorder[tmp];
	buildtree(Li, tmp - 1, Lp + 1, Lp + leftnum - 1, root * 2);
	buildtree(tmp + 1, Ri, Lp + leftnum, Rp, root * 2 + 1);
}
int main()
{
	buildtree(0, 12 ,0, 12, 1);
	for(int i = 1; i <= 15; i++) if(tree[i]) printf("%d ", tree[i]);
	cout << "\n";
	system("pause");
	return 0;
}
