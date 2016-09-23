#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>s;
int n;
int findRoot(int x)
{
	if (s[x] < 0)
		return x;
	else
		return findRoot(s[x]);
}
void Uion(int a,int b)
{
	int ra = findRoot(a);
	int rb = findRoot(b);
	if (ra != rb)
	{
		if (s[ra] <= s[rb])
		{
			s[ra] += s[rb];
			s[rb] = ra;
		}
		else
		{
			s[rb] += s[ra];
			s[ra] = rb;
		}
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		s.clear();
		s.resize(n);
		for (int i = 0; i < n; i++)
		{
			s[i] = -1;
		}
		for (int i = 0; i < n; i++)
		{
			int emp;
			scanf("%d", &emp);
			Uion(i, emp);
		}
		int k = 0;
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] < -1)
				k++;
			if (s[i] == -1)
				x++;
		}
		int count;
		if (s[0] != -1)
			count = (n - x) + k - 2;
		else
			count = (n - x) + k;
		printf("%d\n", count);
	}
	return 0;
}
