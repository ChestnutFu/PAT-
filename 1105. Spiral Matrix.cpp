#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		int m, n;
		int i, j;
		for (i = (int)sqrt((double)N); i >= 1; i--)
		{
			if (N%i == 0)
			{
				n = i;
				m = N / i;
				break;
			}
		}
		vector<int>l(N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &l[i]);
		}
		sort(l.begin(), l.end(), cmp);
		vector<vector<int>>Matrix(m);
		for (i = 0; i < m; i++)
		{
			Matrix[i].resize(n);
		}
		i = 0; j = 0;
		int k = 0;
		int c = 0;
		while (n-2*c>1)
		{
			i = c; j = c;
			for (; i < n-c; i++)
			{
				Matrix[j][i] = l[k];
				k++;
			}
			j++;
			i--;
			for (; j < m-c; j++)
			{
				Matrix[j][i] = l[k];
				k++;
			}
			i--;
			j--;
			for (; i >= c; i--)
			{
				Matrix[j][i] = l[k];
				k++;
			}
			i++;
			j--;
			for (; j >= c + 1; j--)
			{
				Matrix[j][i] = l[k];
				k++;
			}
			c++;
		}
		i = c; j = c;
		for (; j < m - c; j++)
		{
			if (k < N)
			{
				Matrix[j][i] = l[k];
				k++;
			}
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d", Matrix[i][j]);
				if (j != n - 1)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
