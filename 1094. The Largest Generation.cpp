#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<vector<int>>member;
int level[101];
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		member.clear();
		member.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int index, k;
			scanf("%d%d", &index, &k);
			while (k--)
			{
				int child;
				scanf("%d", &child);
				member[index].push_back(child);
			}
		}
		queue<int>q;
		level[1] = 1;
		q.push(1);
		int maxnum = 0;
		int maxlevel;
		int lastlevel = 1;
		int num = 0;
		while (!q.empty())
		{
			int d = q.front();
			if(level[d]==lastlevel)
			{
				num++;
			}
			else
			{
				if (maxnum < num)
				{
					maxnum = num;
					maxlevel = lastlevel;
				}
				lastlevel = level[d];
				num = 1;
			}
			q.pop();
			for (int i = 0; i < member[d].size(); i++)
			{
				int c = member[d][i];
				level[c] = level[d] + 1;
				q.push(c);
			}
		}
		if (maxnum < num)
		{
			maxnum = num;
			maxlevel = lastlevel;
		}
		printf("%d %d", maxnum, maxlevel);
	}
	return 0;
}
