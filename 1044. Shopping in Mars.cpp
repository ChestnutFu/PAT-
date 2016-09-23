#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>num;
vector<int>sum;
int minn;
int m, n;
struct node
{
	int i;
	int j;
	int val;
};
bool cmp(node a,node b)
{
	return a.i<b.i;
}
int find(int left, int right,int x)
{
	if (left >= right)
		return -1;
	int center = (left + right) / 2;
	if (x - sum[center] >= m&&x - sum[center + 1] < m)
	{
		if (x - sum[center] < minn)
			minn = x - sum[center];
		return center;
	}
	else if (x - sum[center] < m)
		return find(left, center, x);
	else
		return find(center, right, x);
		
}
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		num.clear(); num.resize(n + 1);
		sum.clear(); sum.resize(n + 1);
		num[0] = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			sum[i] = sum[i - 1] + num[i];
		}
		vector<node>p;
		minn = 0x6fffffff;
		for (int i = 1; i <= n; i++)
		{
			if (sum[i] >= m)
			{
				int l = find(0, i, sum[i]);
				if (l != -1)
				{
					node a;
					a.i = l + 1;
					a.j = i;
					a.val = sum[i] - sum[l];
					p.push_back(a);
				}
			}
		}
		sort(p.begin(), p.end(), cmp);
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i].val == minn)
				printf("%d-%d\n", p[i].i, p[i].j);
		}
	}
	return 0;
}
