#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int n, k, p;
int nums[21];
vector<int>vec, res;
int maxSum = 0;
void dfs(int start,int k,int n,int sum)
{
	if (k == 0)
	{
		if (n == 0)
		{
			if (sum >= maxSum)
			{
				maxSum = sum;
				res = vec;
			}
		}
	}
	else
	{
		if (n > 0)
		{
			for (int i = start; i <= 20; i++)
			{
				if (n - nums[i] >= 0)
				{
					vec.push_back(i);
					dfs(i, k - 1, n - nums[i], sum + i);
					vec.pop_back();
				}
				else
					break;
			}
		}
	}
}
int main()
{
	while (scanf("%d%d%d",&n,&k,&p)!=EOF)
	{
		for (int i = 0; i <= 20; i++)
		{
			nums[i] = i;
			for (int j = 1; j < p; j++)
				nums[i] *= i;
		}

		dfs(1, k, n, 0);
		if (res.empty())
			printf("Impossible\n");
		else
		{
			printf("%d = ", n);
			printf("%d^%d", res[k - 1], p);
			for (int i = k - 2; i >= 0; i--)
			{
				printf(" + %d^%d", res[i], p);
			}
			printf("\n");
		}
	}
	return 0; 
}
