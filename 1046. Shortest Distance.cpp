#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		vector<int>num(n + 1);
		vector<int>sum(n + 1);
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			sum[i] = sum[i - 1] + num[i];
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int s, e;
			scanf("%d%d", &s, &e);
			int v, u;
			v = s > e ? s : e;
			u = s > e ? e : s;
			int a, b, min;
			a = sum[v - 1] - sum[u - 1];
			b = sum[n] - a;
			min = a < b ? a : b;
			printf("%d\n", min);
		}
	}
	return 0;
}
