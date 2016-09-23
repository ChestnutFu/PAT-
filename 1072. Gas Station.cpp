#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n, m, k, ds;
int map[1020][1020];
vector<vector<int>>dis;
struct node
{
	int sum;
	int min;
	int index;
};
bool cmp(node a, node b)
{
	if (a.min == b.min)
	{
		if (a.sum == b.sum)
			return a.index < b.index;
		else
			return a.sum < b.sum;
	}
	else
		return a.min > b.min;
}
int getNum(char *s)
{
	int x = 0, start = 0;
	if (s[0] == 'G')
	{
		start++;
	}
	while (s[start]!='\0')
	{
		x *= 10;
		x += (s[start] - '0');
		start++;
	}
	if (s[0] == 'G')
		x += n;
	return x;
}
int findMin(vector<bool>visit,vector<int>dist)
{
	int min = -1, minDist = inf;
	for (int i = 1; i < n + m + 1; i++)
	{
		if (visit[i] == false && dist[i] < minDist)
		{
			min = i;
			minDist = dist[i];
		}
	}
	return min;
}
void Dijkastra(int s,vector<int>&dist)
{
	vector<bool>visit(n + m + 1, false);
	dist[s] = 0;
	while (1)
	{
		int v = findMin(visit, dist);
		if (v == -1)break;
		else
		{
			visit[v] = true;
			for (int i = 1; i < n + m + 1; i++)
			{
				if (visit[i] == false && map[v][i] != inf)
				{
					if (dist[i]>dist[v] + map[v][i])
					{
						dist[i] = dist[v] + map[v][i];
					}
				}
			}
		}
	}
}
int main()
{
	while((scanf("%d%d%d%d", &n, &m, &k, &ds) != EOF))
	{
		int i, j;
		for (i = 0; i < n + m + 1; i++)
			for (j = 0; j < n + m + 1; j++)
				map[i][j] = inf;
		char a[6], b[6];
		int distance;
		while (k--)
		{
			scanf("%s%s%d", &a, &b, &distance);
			int x = getNum(a);
			int y = getNum(b);
			map[x][y] = map[y][x] = distance;
		}
		dis.clear();
		dis.resize(m + 1);
		vector<node>can;
		for (i = 1; i <= m; i++)
		{
			dis[i].resize(n + m + 1, inf);
			Dijkastra(i+n,dis[i]);
			bool flag = true;
			node aa;
			int sum = 0;
			int mm = inf;
			for (j = 1; j < n + 1; j++)
			{
				if (dis[i][j] > ds)
				{
					flag = false;
					break;
				}
				sum += dis[i][j];
				if (dis[i][j] < mm)
					mm = dis[i][j];
			}
			if (flag)
			{
				aa.sum = sum;
				aa.min = mm;
				aa.index = i;
				can.push_back(aa);
			}
		}
		sort(can.begin(), can.end(), cmp);
		if (can.size() != 0)
			printf("G%d\n%.1lf %.1lf", can[0].index, (double)can[0].min, (double)can[0].sum / n);
		else
			printf("No Solution\n");
	}
	return 0;
}
