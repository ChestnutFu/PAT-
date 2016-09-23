#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


int main()
{
	int K;
	while (scanf("%d", &K) != EOF)
	{
		int i;
		vector<int>a(K);
		vector<int>sum(K);
		for (i = 0; i < K; i++)
		{
			scanf("%d", &a[i]);
			if (i == 0)
				sum[i] = a[i];
			else
				sum[i] = sum[i - 1] + a[i];
		}
		int begin=0, end=0, maxsum=a[0];
		int j;
		for (i = 1; i < K; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (sum[i] - sum[j] > maxsum)
				{
					begin = j + 1;
					end = i;
					maxsum = sum[i] - sum[j];
				}
			}
		}
		if (maxsum >= 0)
			printf("%d %d %d", maxsum, a[begin], a[end]);
		else
			printf("0 %d %d", a[0], a[K - 1]);
	}
	return 0;
}
