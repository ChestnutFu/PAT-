#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		set<int>nums[51];
		for (int i = 1; i <= n; i++)
		{
			int k, temp;
			scanf("%d", &k);
			while (k--)
			{
				scanf("%d", &temp);
				nums[i].insert(temp);
			}
		}

		int k;
		scanf("%d", &k);
		while (k--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			set<int>D;

			set_intersection(nums[a].begin(), nums[a].end(), nums[b].begin(), nums[b].end(),inserter(D,D.begin()));
			double x = nums[a].size() + nums[b].size() - D.size();
			double m = ((double)D.size() / x) * 100.0;
			printf("%.1lf%%\n", m);
		}
	}
	return 0;
}
