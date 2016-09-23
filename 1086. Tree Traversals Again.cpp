#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int n;
vector<int>post;
struct t
{
	int val;
	t*left, *right;
};
int findRoot(int *in,int x,int len)
{
	int i = 0;
	for (; i < len; i++)
	{
		if (in[i] == x)
			break;
	}
	if (i == len)
		return 0;
	return i;
}
t *BuildTree(int *in, int *pre, int len)
{
	t *root = NULL;
	if (len!=0)
	{
		root = (t*)malloc(sizeof(struct t));
		root->val = *pre;
		int r = findRoot(in, root->val, len);
		int llen = r;
		int rlen = len - 1 - llen;
		root->left = BuildTree(in, pre + 1, llen);
		root->right = BuildTree(in + 1 + llen, pre + 1 + llen, rlen);
	}
	return root;
}
void postRead(t*root)
{
	if (root != NULL)
	{
		postRead(root->left);
		postRead(root->right);
		post.push_back(root->val);
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int N = 2 * n;
		stack<int>s;
		int in[31], pre[31];
		int inP = 0, preP = 0;
		while (N--)
		{
			char str[5];
			scanf("%s", &str);
			if (str[1] == 'o')
			{
				in[inP] = s.top();
				inP++;
				s.pop();
			}
			else
			{
				int x;
				scanf("%d", &x);
				s.push(x);
				pre[preP] = x;
				preP++;
			}
		}
		t *root = BuildTree(in, pre, n);

		post.clear();
		postRead(root);

		for (int i = 0; i < post.size(); i++)
			printf("%d%c", post[i], post.size() - i - 1 ? ' ' : '\n');
	}
	return 0;
}
