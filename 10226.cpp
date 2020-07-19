#include <iostream>
using namespace std;
struct node{
	int count;
	struct node *next[128];
};
node* newnode()
{
	node *ptr = (node*)malloc(sizeof(node));
	for(int i = 0; i < 128; i++) ptr -> next[i] = NULL;
	ptr -> count = 0;
	return ptr;
}

int add(char *s, node *root)
{
	node *p = root;
	for(int i = 0; s[i]; i++)
	{
		if(p->next[s[i]]==NULL)
			p->next[s[i]] = newnode();
		p = p->next[s[i]];
	}
	p->count++;
	return p->count;
}
int n;
char stack[40], s = 0;
void print(node *root)
{
	if(root->count>0)
	{
		for(int i = 0; i < s; i++) printf("%c",stack[i]);
		printf(" %.4f\n", root->count*1.0 / n*100.0);
		return;
	}
	for(int i = 0; i < 128; i++)
	{
		if(root->next[i]!=NULL)
		{
			stack[s++] = i;
			print(root->next[i]);
			s--;
		}
	}
}
int main()
{
    //freopen("10226.txt","w",stdout);
	int t;
	char in[40];
	cin>>t; while(getchar()!='\n');
	gets(in);
	while(t--)
	{
		node *root = newnode();
		n = 0;
		while(gets(in)&&*in)
		{
			n++;
			add(in,root);
		}
		print(root);
		if(t)printf("\n");
	}
	return 0;
}
