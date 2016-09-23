#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int n;//number of nodes in a tree
int m;//number of non-leaf nodes;
int s;//given weight number;
vector<int>w;
vector<vector<int>>tree;
vector<int>path;
int W = 0;
bool cmp(int a, int b)
{
	return w[a] > w[b];
}
void printfpath(vector<int>path)
{
	for (int i = 0; i < path.size(); i++)
	{
		printf("%d", w[path[i]]);
		if (i == path.size() - 1)
			printf("\n");
		else
			printf(" ");
	}
}
void dfs(int v)
{
	path.push_back(v);
	W += w[v];
	if (W == s&&tree[v].size() == 0)
		printfpath(path);
	if (W < s)
	{
		for (int i = 0; i < tree[v].size(); i++)
		{
			dfs(tree[v][i]);
			
			path.pop_back();
			W -= w[tree[v][i]];
		}
	}
}
int main()
{
	while (scanf("%d%d%d",&n,&m,&s)!=EOF)
	{
		w.clear(); tree.clear();
		w.resize(n); tree.resize(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w[i]);
		}
		while (m--)
		{
			int index, k;
			scanf("%d%d", &index, &k);
			while (k--)
			{
				int nn;
				scanf("%d", &nn);
				tree[index].push_back(nn);
			}
		}
		for (int i = 0; i < n; i++)
		{
			sort(tree[i].begin(), tree[i].end(), cmp);
		}
		dfs(0);
	}
	return 0;
}
