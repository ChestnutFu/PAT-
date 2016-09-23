#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int n;
int l;
int map[1001][1001];
struct node
{
	int id;
	int level;
};
int BFS(int s)
{
	int num = 0;
	queue<node>q;
	int p[1001] = { 0 };
	node a;
	a.id = s;
	a.level = 0;
	q.push(a);
	p[a.id] = 1;
	int x;
	int level;
	while (true)
	{
		if (q.empty())
			break;
		x = q.front().id;
		level = q.front().level + 1;
		if (level > l + 1)
			break;
		q.pop();
		if (x != s)
			num++;
		if (p[x] == 0)
		{
			if (x != s)
				p[x] = 1;
		}
		for (int i = 1; i <= map[x][0]; i++)
		{
			a.id = map[x][i];
			a.level = level;
			if (p[a.id] == 0)
			{
				q.push(a);
				p[a.id] = 1;
			}
		}
	}
	return num;
}
int main()
{
	while (scanf("%d%d",&n,&l)!=EOF)
	{
		memset(map, 0, sizeof(int)*(n + 1)*(n + 1));
		for (int i = 1; i <= n; i++)
		{
			int m;
			scanf("%d", &m);
			while (m--)
			{
				int user;
				scanf("%d", &user);
				map[user][0]++;
				int j = map[user][0];
				map[user][j] = i;
			}
		}
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int query;
			scanf("%d", &query);
			int num=BFS(query);
			printf("%d\n", num);
		}
	}
	return 0;
}
