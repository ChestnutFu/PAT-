#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int n, k;
struct node
{
	char name[5];
};
vector<vector<node>>list;
bool cmp(node a, node b)
{
	return strcmp(a.name, b.name) < 0;
}
int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		list.clear();
		list.resize(k + 1);
		char name[5];
		int c;
		int course;
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d", &name, &c);
			node a;
			strcpy(a.name, name);
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &course);
				list[course].push_back(a);
			}
		}
		for (int i = 1; i <= k; i++)
		{
			sort(list[i].begin(), list[i].end(), cmp);
		}
		for (int i = 1; i <= k; i++)
		{
			int len = list[i].size();
			printf("%d %d\n", i, len);
			for (int j = 0; j < len; j++)
			{
				printf("%s\n", list[i][j].name);
			}
		}
	}
	return 0;
}
