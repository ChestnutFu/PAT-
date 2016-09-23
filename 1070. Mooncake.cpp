#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int index;
	double p;
};
bool cmp(node a,node b)
{
	return a.p > b.p;
}
int main()
{
	int n;
	double d, inventory[1000], prices[1000];
	node mooncake[1000];
	while (scanf("%d%lf", &n, &d) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &inventory[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &prices[i]);
			mooncake[i].index = i;
			mooncake[i].p = prices[i] / inventory[i];
		}

		sort(mooncake, mooncake + n, cmp);
		double pri = 0 , inven = 0;
		for (int i = 0; i < n; i++)
		{
			int index = mooncake[i].index;
			if (inven == d)
				break;
			if (d - inven >= inventory[index])
			{
				inven += inventory[index];
				pri += prices[index];
			}
			else
			{
				double x = (d - inven) / inventory[index];
				pri = prices[index] * x + pri;
				inven += (d - inven);
			}
		}
		printf("%.2lf\n", pri);
	}
	return 0;
}
