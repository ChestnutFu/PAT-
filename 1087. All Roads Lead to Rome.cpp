#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<stack>
#define inf 0x7fffffff
using namespace std;
struct node
{
	int cost;
	int happy;
	int path;
	int citynum;
	bool visit;
	int rnums;
	node(){
		cost = inf; happy = 0; path = -1; citynum = 202; visit = false; rnums = 0;
	}
};
int n, k;
vector<int>h;
int G[202][202];
vector<node>citys;
int findmin()
{
	int min = -1, minD = inf;
	for (int i = 0; i < n; i++)
	{
		if (citys[i].visit == false && citys[i].cost < minD)
		{
			minD = citys[i].cost;
			min = i;
		}
	}
	return min;
}
void Dijkstra(int s)
{
	citys[s].happy = h[s];
	citys[s].citynum = 0;
	citys[s].rnums = 1;
	citys[s].cost = 0;
	while (1)
	{
		int v = findmin();
		if (v == -1)break;
		else
		{
			citys[v].visit = true;
			for (int u = 0; u < n; u++)
			{
				if (citys[u].visit == false && G[v][u] < inf)
				{
					if (citys[u].cost>citys[v].cost + G[v][u])
					{
						citys[u].cost = citys[v].cost + G[v][u];
						citys[u].rnums = citys[v].rnums;
						citys[u].happy = citys[v].happy + h[u];
						citys[u].citynum = citys[v].citynum + 1;
						citys[u].path = v;
					}
					else if (citys[u].cost == citys[v].cost + G[v][u])
					{
						citys[u].rnums += citys[v].rnums;
						if (citys[u].happy < citys[v].happy + h[u])
						{
							citys[u].happy = citys[v].happy + h[u];
							citys[u].citynum = citys[v].citynum + 1;
							citys[u].path = v;
						}
						else if (citys[u].happy == citys[v].happy + h[u]
							&& citys[u].citynum>citys[v].citynum + 1)
						{
							citys[u].citynum = citys[v].citynum + 1;
							citys[u].path = v;
						}
					}

				}
			}
		}
	}
}
int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		int end;
		map<string, int>c2i;
		map<int, string>i2c;
		string cityname;
		cin >> cityname;
		int i = 0, j;
		c2i[cityname] = i; i2c[i] = cityname;
		if (cityname == "ROM")
			end = i;
		h.clear(); h.resize(n);
		h[0] = 0;
		for (i = 1; i < n; i++)
		{
			cin >> cityname;
			c2i[cityname] = i; i2c[i] = cityname;
			scanf("%d", &h[i]);
			if (cityname == "ROM")
				end = i;
		}
		for (i = 0; i < 202; i++)
			for (j = 0; j < 202; j++)
				G[i][j] = inf;

		while (k--)
		{
			string c1, c2;
			int cost;
			cin >> c1 >> c2 >> cost;
			G[c2i[c1]][c2i[c2]] = G[c2i[c2]][c2i[c1]] = cost;
		}
		citys.clear();
		citys.resize(n);
		Dijkstra(0);
		printf("%d %d %d %d\n", citys[end].rnums, citys[end].cost, citys[end].happy, citys[end].happy / citys[end].citynum);
		
		cout << i2c[0];
		stack<int>s;
		int p = end;
		while (p!=0)
		{
			s.push(p);
			p = citys[p].path;
		}
		while (!s.empty())
		{
			cout << "->" << i2c[s.top()];
			s.pop();
		}
	}
}
