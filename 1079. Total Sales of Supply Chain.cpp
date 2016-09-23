#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int n;
double p;
double r;
vector<vector<int>>chain;
vector<double>price;
struct node
{
	int index;
	double p;
};
void BFS(int root)
{
	node a;
	a.index = root;
	a.p = price[root];
	queue<node>q;
	q.push(a);
	while (!q.empty())
	{
		int v = q.front().index;
		double pri = q.front().p;
		q.pop();
		if (!chain[v][0] == 0)
		{
			for (int i = 1; i <= chain[v][0]; i++)
			{
				a.index = chain[v][i];
				a.p = pri + pri*r / 100;
				price[a.index] = a.p;
				q.push(a);
			}
		}
	}
}
int main()
{
	while (scanf("%d %lf %lf",&n,&p,&r)!=EOF)
	{
		chain.clear();
		chain.resize(n);
		price.clear();
		price.resize(n);
		price[0] = p;
		map<int, int>retailers;
		for (int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);
			chain[i].push_back(k);
			if (k == 0)
			{
				int emp;
				scanf("%d", &emp);
				retailers[i] = emp;
			}
			else
			{
				while (k--)
				{
					int emp;
					scanf("%d", &emp);
					chain[i].push_back(emp);
				}
			}
		}
		BFS(0);
		double P = 0;
		map<int, int>::iterator it;
		for (it = retailers.begin(); it != retailers.end(); it++)
		{
			P += price[it->first] * it->second;
		}
		printf("%.1lf\n", P);
	}
	return 0;
}
