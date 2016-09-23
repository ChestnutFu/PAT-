#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp1(int a,int b)
{
	return a > b;
}
bool cmp2(int a, int b)
{
	return a < b;
}
int min(int a,int b)
{
	return a < b ? a : b;
}
int main()
{
	int nc, np;
	vector<int>c1, c2, p1, p2;
	while (scanf("%d",&nc)!=EOF)
	{
		int emp;
		for (int i = 0; i < nc; i++)
		{
			scanf("%d", &emp);
			if (emp > 0)
				c1.push_back(emp);
			else
				c2.push_back(emp);
		}
		scanf("%d", &np);
		for (int i = 0; i < np;i++)
		{
			scanf("%d", &emp);
			if (emp > 0)
				p1.push_back(emp);
			else
				p2.push_back(emp);
		}
		int maxx = 0;
		sort(c1.begin(), c1.end(), cmp1);
		sort(p1.begin(), p1.end(), cmp1);
		int len = min(c1.size(), p1.size());
		for (int i = 0; i < len; i++)
		{
			maxx += (c1[i] * p1[i]);
		}
		sort(c2.begin(), c2.end(), cmp2);
		sort(p2.begin(), p2.end(), cmp2);
		len = min(c2.size(), p2.size());
		for (int i = 0; i < len; i++)
		{
			maxx += (c2[i] * p2[i]);
		}
		printf("%d\n", maxx);
	}
	return 0;
}
