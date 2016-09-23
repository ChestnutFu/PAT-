#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>  
#include<vector>  
#include<queue>  
#include<string>  
#include<map>  
#include<iostream>  
#include<cstring>  
#include<algorithm>  
using namespace std;
typedef long long LL;
const int INF = 0x7FFFFFFF;
const int maxn = 5e2 + 10;
int n, m, x, y, z, S, T, dm, tm;
int d[maxn][maxn], t[maxn][maxn];
int dis[maxn], cost[maxn], vis[maxn];
vector<int> ans[2];

void dfs(int x)
{
	if (x == S) { ans[0].push_back(x); return; }
	for (int i = 0; i < n; i++)
	{
		if (!d[i][x]) continue;
		if (dis[x] != dis[i] + d[i][x]) continue;
		if (cost[x] != cost[i] + t[i][x]) continue;
		dfs(i);
		ans[0].push_back(x);
	}
}

void Dfs(int x)
{
	if (x == S) { ans[1].push_back(x); return; }
	for (int i = 0; i < n; i++)
	{
		if (!t[i][x]) continue;
		if (dis[x] != dis[i] + t[i][x]) continue;
		if (cost[x] != cost[i] + 1) continue;
		Dfs(i);
		ans[1].push_back(x);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d%d%d", &x, &y, &z);
		scanf("%d%d", &d[x][y], &t[x][y]);
		if (!z) d[y][x] = d[x][y], t[y][x] = t[x][y];
	}
	scanf("%d%d", &S, &T);
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[S] = 0;
	while (true)
	{
		int now = -1;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] || dis[i] == -1) continue;
			if (now == -1 || dis[now] > dis[i]) now = i;
		}
		if (now == -1) break;
		vis[now] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!d[now][i]) continue;
			if (dis[i] == -1 || dis[now] + d[now][i] < dis[i])
			{
				dis[i] = dis[now] + d[now][i];
				cost[i] = cost[now] + t[now][i];
			}
			else if (dis[now] + d[now][i] == dis[i])
			{
				cost[i] = min(cost[i], cost[now] + t[now][i]);
			}
		}
	}
	dfs(T); dm = dis[T];
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[S] = 0; cost[S] = 0;
	while (true)
	{
		int now = -1;
		for (int i = 0; i < n; i++)
		{
			if (vis[i] || dis[i] == -1) continue;
			if (now == -1 || dis[now] > dis[i]) now = i;
		}
		if (now == -1) break;
		vis[now] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!t[now][i]) continue;
			if (dis[i] == -1 || dis[now] + t[now][i] < dis[i])
			{
				dis[i] = dis[now] + t[now][i];
				cost[i] = cost[now] + 1;
			}
			else if (dis[now] + t[now][i] == dis[i])
			{
				cost[i] = min(cost[i], cost[now] + 1);
			}
		}
	}
	Dfs(T); tm = dis[T];
	if (ans[0] == ans[1])
	{
		printf("Distance = %d; Time = %d:", dm, tm);
		for (int i = 0; i < ans[0].size(); i++)
		{
			printf(" %d", ans[0][i]);
			if (i == ans[0].size() - 1) printf("\n");
			else printf(" ->");
		}
	}
	else
	{
		printf("Distance = %d:", dm);
		for (int i = 0; i < ans[0].size(); i++)
		{
			printf(" %d", ans[0][i]);
			if (i == ans[0].size() - 1) printf("\n");
			else printf(" ->");
		}
		printf("Time = %d:", tm);
		for (int i = 0; i < ans[1].size(); i++)
		{
			printf(" %d", ans[1][i]);
			if (i == ans[1].size() - 1) printf("\n");
			else printf(" ->");
		}
	}
	return 0;
}
