#include<iostream>
#include<queue>
using namespace std;
struct node{
	int val;
	node *ch[2];
};
queue<node>list;
int findmark(int x,int in[],int len)
{
	int i;
	for (i = 0; i < len; i++)
		if (in[i] == x)
			break;
	return i;
}
node *restore(int pos[],int in[],int len)
{
if (len <= 0)
		return NULL;
	node *p = new node();
	p->val = pos[len - 1];
	p->ch[0] = p->ch[1] = NULL;
	int mark = findmark(p->val, in, len);
	p->ch[0] = restore(pos, in, mark);
	int *rp = pos + mark;
	int *ri = in + mark + 1;
	int rlen = len - mark - 1;
	p->ch[1] = restore(rp, ri, rlen);
	return p;
}
int main()
{
	int N;
	while (cin >> N)
	{
		int pos[31], inorder[31];
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> pos[i];
		}
		for (i = 0; i < N; i++)
		{
			cin >> inorder[i];
		}
		node *root = restore(pos, inorder, N);
		printf("%d", root->val);
		if (root->ch[0])
			list.push(*root->ch[0]);
		if (root->ch[1])
			list.push(*root->ch[1]);
		while (!list.empty())
		{
			node a = list.front();
			printf(" %d", a.val);
			list.pop();

			if (a.ch[0])
				list.push(*a.ch[0]);
			if (a.ch[1])
				list.push(*a.ch[1]);
		}
	}
	return 0;
}
