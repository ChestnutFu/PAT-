#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	int n;
	double p, r;
	while (scanf("%d%lf%lf", &n, &p, &r) != EOF)
	{
		r /= 100.0;
		int root;
		vector<vector<int>>mem(n);
		vector<double>price(n);
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			if (temp == -1)
			{
				root = i;
				price[i] = p;
			}
			else
			{
				mem[temp].push_back(i);
			}
		}
		queue<int>q;
		q.push(root);
		while (!q.empty())
		{
			int a = q.front();
			q.pop();

			for (int i = 0; i < mem[a].size(); i++)
			{
				price[mem[a][i]] = price[a] * r + price[a];
				q.push(mem[a][i]);
			}
		}

		double max = 0;
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			if (mem[i].size() == 0)
			{
				if (price[i] > max)
				{
					max = price[i];
					num = 1;
				}
				else if (max == price[i])
				{
					num++;
				}
			}
		}
		printf("%.2lf %d\n", max, num);
	}
	return 0;
}
