#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int n;
vector<vector<int>>tree;
vector<int>list;
vector<int>dist;
set<int>deeps;
void bfs(int s)
{
	dist.clear();
	dist.assign(n + 1, 0);
	vector<bool>visit(n + 1, false);
	
	int maxdeep = 0;

	queue<int>q;
	q.push(s);
	visit[s] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < tree[x].size(); i++)
		{
			int v = tree[x][i];
			if (visit[v] == false)
			{
				dist[v] = dist[x] + 1;
				if (dist[v]>maxdeep)
					maxdeep = dist[v];
				q.push(v);
				visit[v] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == maxdeep)
			deeps.insert(i);
	}
}
int findRoot(int a)
{
	if (list[a] < 0)
		return a;
	else
		return findRoot(list[a]);
}
void Uion(int a,int b)
{
	int ra = findRoot(a);
	int rb = findRoot(b);
	if (ra != rb)
	{
		if (list[ra] <= list[rb])
		{
			list[ra] += list[rb];
			list[rb] = ra;
		}
		else
		{
			list[rb] += list[ra];
			list[ra] = rb;
		}
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		tree.clear();
		tree.resize(n + 1);
		list.clear();
		list.assign(n + 1, -1);
		for (int i = 0; i < n - 1;i++)
		{
			int v, u;
			scanf("%d%d", &v, &u);
			tree[v].push_back(u);
			tree[u].push_back(v);
			Uion(v, u);
		}
		int com = 0;
		for (int i = 1; i <= n; i++)
		{
			if (list[i] < 0)
				com++;
		}
		if (com != 1)
		{
			printf("Error: %d components\n", com);
		}
		else
		{
			deeps.clear();
			bfs(1);
			set<int>::iterator it;
			it = deeps.begin();
			bfs(*it);
			for (it = deeps.begin(); it != deeps.end(); it++)
				printf("%d\n", *it);
		}
	}
}
