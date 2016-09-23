#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n;
	double p, r;
	while (scanf("%d%lf%lf",&n,&p,&r)!=EOF)
	{
		vector<vector<int>>mem(n);
		for (int i = 0; i < n;i++)
		{
			int k;
			scanf("%d", &k);
			while (k--)
			{
				int child;
				scanf("%d", &child);
				mem[i].push_back(child);
			}
		}
		vector<double>price(n);
		price[0] = p;
		queue<int>q;
		q.push(0);
		while (!q.empty())
		{
			int a = q.front();
			q.pop();

			double childp = price[a] + price[a] * (r / 100);
			for (int i = 0; i < mem[a].size(); i++)
			{
				price[mem[a][i]] = childp;
				q.push(mem[a][i]);
			}
		}
		double min = 99999999.99;
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			if (mem[i].size() == 0)
			{
				if (price[i] < min)
				{
					min = price[i];
					num = 1;
				}
				else if (price[i] == min)
					num++;
			}
		}
		printf("%.4lf %d\n", min, num);
	}
	return 0;
}
