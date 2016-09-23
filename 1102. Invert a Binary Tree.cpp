#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct node
{
	int root;
	int left;
	int right;
	node(){ root = -1; left = -1; right = -1; }
};
vector<node>tree;
int findRoot(int n)
{
	for (int i = 0; i < n; i++)
		if (tree[i].root == -1)
			return i;
}
void printL(vector<int>nums,int n)
{
	for (int i = 0; i < n; i++)
		printf("%d%c", nums[i], n - 1 - i ? ' ' : '\n');
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		tree.clear(); 
		tree.resize(n);
		int i;
		char l[4];
		for (i = 0; i < n; i++)
		{
			scanf("%s", &l);
			if (l[0] != '-')
			{
				tree[i].right = l[0] - '0';
				tree[l[0] - '0'].root = i;
			}
			scanf("%s", &l);
			if (l[0] != '-')
			{
				tree[i].left= l[0] - '0';
				tree[l[0] - '0'].root = i;
			}
		}
		int root = findRoot(n);
		vector<int>printList;
		//层序遍历
		queue<int>q;
		q.push(root);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			printList.push_back(v);
			if (tree[v].left != -1)q.push(tree[v].left);
			if (tree[v].right != -1)q.push(tree[v].right);
		}
		printL(printList, n);
		printList.clear();
		//前序遍历
		int w = root;
		stack<int>s;
		while (w!=-1||!s.empty())
		{
			while (w!=-1)
			{
				s.push(w);
				w = tree[w].left;
			}
			if (!s.empty())
			{
				int a = s.top();
				s.pop();
				printList.push_back(a);
				w = tree[a].right;
			}
		}
		printL(printList, n);
	}
	return 0;
}
