#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int count;
	struct node *next[128];
} node;
inline node* newnode()
{
	register int i;
	node *ptr = (node*)malloc(sizeof(node));
	for(i = 0; i < 128; i++) ptr -> next[i] = NULL;
	ptr -> count = 0;
	return ptr;
}

inline int add(char *s, node *root)
{
	register int i;
	node *p = root;
	for(i = 0; s[i]; i++)
	{
		if(p->next[s[i]]==NULL)
			p->next[s[i]] = newnode();
		p = p->next[s[i]];
	}
	p->count++;
	return p->count;
}
int n, s = 0;
char stack[40];
void print(node *root)
{
	register int j, k;
	if(root->count>0)
	{
		for(j = 0; j < s; j++) printf("%c",stack[j]);
		printf(" %.4f\n", root->count*1.0 / n*100.0);
		return;
	}
	for(k = 0; k < 128; k++)
	{
		if(root->next[k]!=NULL)
		{
			stack[s++] = k;
			print(root->next[k]);
			s--;
		}
	}
}
int main()
{
	int t;
	char in[40];
	scanf(" %d",&t); while(getchar()!='\n');
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
