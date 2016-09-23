#include<iostream>
#include<stdio.h>
#include<vector>
#define inf 0x6FFFFFF
using namespace std;
int N;//节点/城市
int M;//边/路
int C1, C2;
int map[501][501];
int teams[501];
int findmin(vector<bool>&collected,vector<int>&dist)
{
	int min, mindis = inf;
	for (int i = 0; i < N; i++)
	{
		if (collected[i] == false && dist[i] < mindis)
		{
			mindis = dist[i];
			min = i;
		}
	}
	if (mindis == inf)
		return -1;
	else
		return min;
}
void Dijkstra(int s,vector<int>&dist,vector<int>&path,vector<int>&teamAmount,vector<int>&shortpath)
{
	int i;
	vector<bool>collected(N, false);
	dist[s] = 0;
	teamAmount[s] = teams[s];
	shortpath[s] = 1;
	int v;
	while (1)
	{
		 v = findmin(collected, dist);
		if (v == -1)break;
		else
		{
			int w;
			collected[v] = true;
			for (i = 0; i < N; i++)
			{
				if (collected[i] == false && map[i][v]<inf)
				{
					if (dist[i] > dist[v] + map[i][v])
					{
						path[i] = v;
						shortpath[i] = shortpath[v];
						dist[i] = dist[v] + map[i][v];
						teamAmount[i] = teamAmount[v] + teams[i];
					}
					else if (dist[i] == dist[v] + map[i][v])
					{
						shortpath[i] += shortpath[v];
						if (teamAmount[i] < teamAmount[v] + teams[i])
						{
							path[i] = v;
							teamAmount[i] = teamAmount[v] + teams[i];
						}
					}
				}
			}
		}
	}
}
int main()
{
	while (scanf("%d%d%d%d",&N,&M,&C1,&C2)!=EOF)
	{
		int i, j;
		for (i = 0; i < N; i++)
			scanf("%d", &teams[i]);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				map[i][j] = inf;
		for (i = 0; i < M; i++)
		{
			int s, d, l;
			scanf("%d%d%d", &s, &d, &l);
			map[s][d] = map[d][s] = l;
		}
		vector<int>path(N, -1);
		vector<int>dist(N, inf);
		vector<int>shortpath(N, 0);
		vector<int>teamAmount(N, 0);
		Dijkstra(C1, dist, path, teamAmount,shortpath);
		printf("%d %d\n", shortpath[C2], teamAmount[C2]);
	}
	return 0;
}
