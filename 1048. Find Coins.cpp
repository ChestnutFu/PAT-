#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		vector<int>coins(1000, 0);
		int index;
		while (n--)
		{
			scanf("%d", &index);
			coins[index]++;
		}
		int i;
		for (i = 0; i <= m; i++)
		{
			if (i < m - i)
			{
				if (coins[i] != 0 && coins[m - i] != 0)
					break;
			}
			else if (i == m - i)
			{
				if (coins[i] > 1)
					break;
			}
		}
		if (i != m + 1)
			printf("%d %d\n", i, m - i);
		else
			printf("No Solution\n");
	}
	return 0;
}
