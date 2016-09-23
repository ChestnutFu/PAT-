#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int main()
{
	int m, n;
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		map<int, int>ma;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int st;
				scanf("%d", &st);
				ma[st]++;
			}
		}
		int max = 0;
		int s;
		for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
		{
			if (it->second > max)
			{
				max = it->second;
				s = it->first;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
