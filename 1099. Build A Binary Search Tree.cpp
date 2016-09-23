#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct node
{
	int val;
	int index;
	int left;
	int right;
};

bool cmp(int a,int b)
{
	return a < b;
}
int main()
{
	//该树的前序遍历结果是个递增的数组
	//在把树前序遍历的同时把排好序的数组一个一个插入就行了
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		vector<node>tree(n);
		vector<int>num(n);
		for (int i = 0; i < n; i++)
		{
			tree[i].index = i;
			scanf("%d%d", &tree[i].left, &tree[i].right);
		}

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		sort(num.begin(), num.end(), cmp);

		stack<node>s;
		int x = 0;
		int j = 0;
		while (x!=-1||!s.empty())
		{
			while (x != -1)
			{//左孩子入栈
				s.push(tree[x]);
				x = tree[x].left;
			}
			if (!s.empty())
			{
				int v = s.top().index;
				s.pop();
				tree[v].val = num[j++];
				x = tree[v].right;
			}
		}
		queue<int>q;
		printf("%d", tree[0].val);
		if (tree[0].left != -1)q.push(tree[0].left);
		if (tree[0].right != -1)q.push(tree[0].right);
		while (!q.empty())
		{
			int w = q.front();
			q.pop();
			printf(" %d", tree[w].val);
			if (tree[w].left != -1)q.push(tree[w].left);
			if (tree[w].right != -1)q.push(tree[w].right);
		}
		printf("\n");
	}
	return 0;
}
