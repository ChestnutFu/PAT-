#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
using namespace std;
struct node
{
	int root;
	int left;
	int right;
	node(){ root = -1; left = -1; right = -1; }
};
vector<node>tree;
int n;
int last;
bool Iscomplete(int root,int n)
{
	queue<int>q;
	q.push(root);
	int cur = 0;
	while (q.front()!=-1)
	{
		int v = q.front();
		last = v;
		q.pop();
		cur++;
		q.push(tree[v].left);
		q.push(tree[v].right);
	}
	if (cur == n)
		return true;
	else
		return false;
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		tree.clear();
		tree.resize(n);
		int i;
		for (i = 0; i < n; i++)
		{
			string tmp;

			cin >> tmp;
			if (tmp[0] != '-')
			{
				int temp = atoi(tmp.c_str());
				tree[i].left = temp;
				tree[temp].root = i;
			}
			cin >> tmp;
			if (tmp[0] != '-')
			{
				int temp = atoi(tmp.c_str());
				tree[i].right = temp;
				tree[temp].root = i;
			}
		}
		int root;
		for (i = 0; i < n;i++)
			if (tree[i].root == -1)
			{
				root = i;
				break;
			}
		if (Iscomplete(root,n))
			printf("YES %d\n", last);
		else
			printf("NO %d\n", root);

	}
	return 0;
}
