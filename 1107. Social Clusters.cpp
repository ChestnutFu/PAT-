#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int>people;
bool cmp(int a, int b)
{
	return a > b;
}
int findroot(int x)
{
	if (people[x] < 0)
		return x;
	else
		return findroot(people[x]);
}
void Uion(int x, int y)
{
	int rx = findroot(x);
	int ry = findroot(y);

	if (people[rx] > people[ry])
	{
		people[ry] += people[rx];
		people[rx] = ry;
	}
	else
	{
		people[rx] += people[ry];
		people[ry] = rx;
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		vector<int>h[1002];
		people.clear();
		people.resize(n + 1, -1);
		int i;
		for (i = 1; i <= n; i++)
		{
			int k;
			scanf("%d:", &k);
			while (k--)
			{
				int hobby;
				scanf("%d", &hobby);
				h[hobby].push_back(i);
			}
		}
		for (i = 1; i <= 1000; i++)
		{
			if (h[i].size() > 1)
			{
				int j;
				for (j = 1; j < h[i].size(); j++)
				{
					Uion(h[i][0], h[i][j]);
				}
			}
		}
		vector<int>s;
		for (i = 1; i <= n; i++)
		{
			if (people[i] < 0)
				s.push_back(people[i] * -1);
		}
		printf("%d\n", s.size());
		sort(s.begin(), s.end(), cmp);
		for (i = 0; i < s.size() - 1; i++)
			printf("%d ", s[i]);
		printf("%d\n", s[i]);
	}
	return 0;
}
