#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long int>list;
bool cmp(long long int a,long long int b)
{
	return a< b;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		list.clear();
		list.resize(n);
		long long int x;
		vector<long long int>L;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &x);
			list[i] = x;
		}

		vector<long long int>leftmax(n);
		vector<long long int>rightmin(n);
		int j;
		for (j = 0; j < n; j++)
		{
			if (j == 0)
				leftmax[j] = list[j];
			else
			{
				if (list[j]>leftmax[j - 1])
					leftmax[j] = list[j];
				else
					leftmax[j] = leftmax[j - 1];
			}
		}
		for (j = n - 1; j >= 0; j--)
		{
			if (j==n-1)
				rightmin[n - 1] = list[j];
			else
			{
				if (list[j] < rightmin[j + 1])
					rightmin[j] = list[j];
				else
					rightmin[j] = rightmin[j + 1];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (list[i] < rightmin[i + 1])
					L.push_back(list[i]);
			}
			else if (i == n - 1)
			{
				if (list[i] > leftmax[i - 1])
					L.push_back(list[i]);
			}
			else
			{
				if (list[i] > leftmax[i - 1] && list[i] < rightmin[i + 1])
					L.push_back(list[i]);
			}
		}
		printf("%d\n", L.size());
		sort(L.begin(), L.end(), cmp);
		for (int i = 0; i < L.size(); i++)
		{
			printf("%d", L[i]);
			if (i != L.size() - 1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
