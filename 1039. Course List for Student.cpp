#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n, k;
vector<vector<int>>stu(26 * 26 * 26 * 10);
bool cmp(int a,int b)
{
	return a < b;
}
int main()
{
	char name[5];
	while (scanf("%d%d", &n, &k) != EOF)
	{
		while (k--)
		{
			int index, kk;
			scanf("%d%d", &index, &kk);
			while (kk--)
			{
				scanf("%s", &name);
				int x = 0;
				x += (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
				stu[x].push_back(index);
			}
		}
		while (n--)
		{
			scanf("%s", &name);
			int x = 0;
			x += (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
			printf("%s %d", name, stu[x].size());
			sort(stu[x].begin(), stu[x].end(), cmp);
			for (int i = 0; i < stu[x].size(); i++)
			{
				printf(" %d", stu[x][i]);
			}
			printf("\n");
		}
	}
	return 0;
}
