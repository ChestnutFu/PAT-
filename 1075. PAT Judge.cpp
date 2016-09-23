#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	int total;
	int rank;
	int solve;
	int has;
	vector<int>marks;
};
vector<node>stu;
bool cmp(node a,node b)
{
	if (a.total == b.total)
	{
		if (a.solve == b.solve)
		{
			if (a.has == b.has)
				return a.id < b.id;
			else
				return a.has > b.has;
		}

		else
			return a.solve > b.solve;
	}
	else
		return a.total > b.total;
}

int main()
{
	int n, k, m;
	while (scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		stu.clear();
		stu.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			stu[i].id = i;
			stu[i].total = 0;
			stu[i].solve = 0;
			stu[i].marks.assign(k + 1, -1);
			stu[i].has = -1;
		}
		vector<int>score(k + 1);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &score[i]);
		}
		while (m--)
		{
			int id, pid, sco;
			scanf("%d%d%d", &id, &pid, &sco);
			if (sco >= 0)
				stu[id].has = 1;
			if (stu[id].marks[pid] < sco)
				stu[id].marks[pid] = sco;
			if (stu[id].marks[pid] == -1 && sco == -1)
				stu[id].marks[pid] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (stu[i].marks[j]>0)
					stu[i].total += stu[i].marks[j];
				if (stu[i].marks[j] == score[j])
					stu[i].solve++;
			}
		}

		sort(stu.begin(), stu.end(), cmp);

		stu[0].rank = 1;
		for (int i = 1; i <= n; i++)
		{
			if (stu[i].total == stu[i - 1].total)
				stu[i].rank = stu[i - 1].rank;
			else
				stu[i].rank = i + 1;
		}

		for (int i = 0; i <= n; i++)
		{
			if (stu[i].total >= 0 && stu[i].has == 1)
			{
				printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
				for (int j = 1; j <= k; j++)
				{
					if (stu[i].marks[j] >= 0)
						printf(" %d", stu[i].marks[j]);
					else
						printf(" -");
				}
				printf("\n");
			}
		}
	}
}
