#include<iostream>
#include<stdio.h>
#include<vector>
#define inf 0x6fffffff
using namespace std;
struct edge
{
	int end;
	int dis;
	edge(int e,int d)
	{
		end = e;
		dis = d;
	}
};
int Cmax, n, Sp, m;
vector<vector<edge>>map;
vector<int>bikes;
vector<int>dist;
vector<vector<int>>allPath;
vector<int>possblePath;
vector<int>bestPath;
int minSend = inf;
int minCollect = inf;
int findMin(vector<bool>visit)
{
	int minDist = inf, min = -1;
	for (int i = 0; i <= n; i++)
	{
		if (minDist > dist[i] && visit[i] == false)
		{
			min = i;
			minDist = dist[i];
		}
	}
	return min;
}
void Dijkstra(int s)
{
	vector<bool>visit(n + 1, false);
	allPath.clear();
	allPath.resize(n + 1);
	dist[s] = 0;

	while (1)
	{
		int v = findMin(visit);
		if (v == -1)break;
		else
		{
			visit[v] = true;
			int j, u, d;
			for (j = 0; j < map[v].size(); j++)
			{
				u = map[v][j].end;
				d = map[v][j].dis;
				if (dist[u] > dist[v] + d)
				{
					allPath[u].clear();
					allPath[u].push_back(v);
					dist[u] = dist[v] + d;
				}
				else if (dist[u] == dist[v] + d)
				{
					allPath[u].push_back(v);
				}
			}
		}
	}
}
void findBest(int u)
{
	possblePath.push_back(u);
	if (u == 0)
	{
		int send = 0, collect = 0;
		for (int i = possblePath.size() - 1; i >= 0; i--)
		{
			int x = possblePath[i];
			if (bikes[x] > Cmax / 2)
			{
				collect += bikes[x] - Cmax / 2;
			}
			else if (bikes[x] < Cmax / 2)
			{
				collect -= (Cmax / 2 - bikes[x]);
				if (collect < 0)
				{
					send += -1 * collect;
					collect = 0;
				}
			}
		}
		if (send < minSend)
		{
			minSend = send;
			minCollect = collect;
			bestPath = possblePath;
		}
		else if (send==minSend&&collect<minCollect)
		{
			minCollect = collect;
			bestPath = possblePath;
		}
		return;
	}
	else
	{
		for (int i = 0; i < allPath[u].size(); i++)
		{
			findBest(allPath[u][i]);
			possblePath.pop_back();
		}
	}
}
int main()
{
	while (scanf("%d%d%d%d",&Cmax,&n,&Sp,&m)!=EOF)
	{
		map.clear();
		map.resize(n + 1);
		bikes.clear();
		bikes.resize(n + 1);
		bikes[0] = Cmax / 2;
		int i;
		for (i = 1; i <= n; i++)
			scanf("%d", &bikes[i]);
		int c1, c2, times;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &c1, &c2, &times);
			map[c1].push_back(edge(c2, times));
			map[c2].push_back(edge(c1, times));
		}
		dist.clear();
		dist.assign(n + 1, inf);
		Dijkstra(0);
		findBest(Sp);

		printf("%d 0", minSend);
		for (int i = bestPath.size() - 2; i >= 0; i--)
			printf("->%d", bestPath[i]);
		printf(" %d\n", minCollect);
	}
	return 0;
}
