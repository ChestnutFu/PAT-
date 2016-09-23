#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define INF 0x6FFFFFFF
using namespace std;
typedef struct Node{
	int dist;
	int cost;
	int path;
	Node()
	{
		dist = INF;
		cost = INF;
		path = -1;
	}
}Node;
struct Edge{
	int end;
	int dist;
	int cost;
	Edge(int e, int d, int c)
	{
		end = e;
		dist = d;
		cost = c;
	}
};
int n, m, s, d;
vector<vector<Edge>>edge;
vector<Node>city;
std::vector<bool>visit;
int findMin()
{
	int minDist = INF, min = -1;
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == false && city[i].dist < minDist)
		{
			min = i;
			minDist = city[i].dist;
		}
	}
	return min;
}
void Dijktra(int s)
{
	city[s].dist = 0;
	city[s].cost = 0;

	while (1)
	{
		int v = findMin();
		if (v == -1)break;
		else
		{
			visit[v] = true;

			for (int i = 0; i < edge[v].size(); i++)
			{
				int u = edge[v][i].end;
				int dis = edge[v][i].dist;
				int cos = edge[v][i].cost;
				if (visit[u] == false)
				{
					if (city[u].dist > city[v].dist + dis)
					{
						city[u].dist = city[v].dist + dis;
						city[u].cost = city[v].cost + cos;
						city[u].path = v;
					}
					else if (city[u].dist == city[v].dist + dis
						&&city[u].cost > city[v].cost + cos)
					{
						city[u].cost = city[v].cost + cos;
						city[u].path = v;
					}
				}
			}
		}
	}
}
int main()
{
	while (scanf("%d%d%d%d",&n,&m,&s,&d)!=EOF)
	{
		edge.clear();
		edge.resize(n);
		while (m--)
		{
			int u, v, dis, cos;
			scanf("%d%d%d%d", &u, &v, &dis, &cos);

			edge[u].push_back(Edge(v, dis, cos));
			edge[v].push_back(Edge(u, dis, cos));
		}

		city.clear();
		city.resize(n);
		visit.clear();
		visit.assign(n, false);
		Dijktra(s);

		int end = d;
		stack<int>s;
		while (end!=-1)
		{
			s.push(end);
			end = city[end].path;
		}
		while (!s.empty())
		{
			printf("%d ", s.top());
			s.pop();
		}
		printf("%d %d\n", city[d].dist, city[d].cost);
	}
	return 0;
}
