#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int>s;
int n;
long long int p;
bool cmp(long long int a,long long int b)
{
	return a < b;
}
int find(int left,int right,long long int x)
{
	while(left <= right)
	{
		int center = (left + right) / 2;

		if (s[center] == x)
			return center;
		else if (s[center] > x)
			right = center - 1;
		else
			left = center + 1;
	}
	return right;
}
int main()
{
	while (scanf("%d%lld",&n,&p)!=EOF)
	{
		s.clear();
		s.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &s[i]);
		sort(s.begin(), s.end(), cmp);
		int maxx = 0;
		for (int i = 0; i < n; i++)
		{
			int M;
			if (s[i] * p > s[n - 1])
				M = n - 1;
			else
				M = find(i, n - 1, s[i] * p);
			if (M - i + 1 > maxx&&s[M] <= s[i] * p)
				maxx = M - i + 1;
		}
		printf("%d\n", maxx);
	}
	return 0;
}
