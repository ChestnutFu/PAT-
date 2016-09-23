#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int index;
	int final;
	int ge;
	int gi;
	int rank;
	vector<int>choice;
};
struct snode
{
	int last_rank;
	int num;
	vector<int>stu;
};
bool cmp(node a,node b)
{
	//final->ge
	if (a.final == b.final)
		return a.ge > b.ge;
	else
		return a.final > b.final;
}
bool cmp1(int a, int b)
{
	return a < b;
}
int main()
{
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		vector<snode>school(m);
		int i, j;
		//输入
		for (i = 0; i < m; i++)
			scanf("%d", &school[i].num);
		vector<node>stu(n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &stu[i].ge, &stu[i].gi);
			stu[i].index = i; stu[i].final = stu[i].ge + stu[i].gi;
			int c;
			for (j = 0; j < k; j++)
			{
				scanf("%d", &c);
				stu[i].choice.push_back(c);
			}
		}
		//排序
		sort(stu.begin(), stu.end(), cmp);
		//排名
		stu[0].rank = 1;
		for (i = 1; i < n; i++)
		{
			if (stu[i].final == stu[i - 1].final
				&&stu[i].ge == stu[i - 1].ge)
			{
				stu[i].rank = stu[i - 1].rank;
			}
			else
				stu[i].rank = i + 1;
		}
	
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < k; j++)
			{
				int s = stu[i].choice[j];
				//如果还有名额
				if (school[s].num > 0)
				{
					school[s].last_rank = stu[i].rank;
					school[s].num--;
					school[s].stu.push_back(stu[i].index);
					break;
				}
				//如果没有名额了但是排名一样
				if (school[s].num == 0 
					&& school[s].last_rank == stu[i].rank)
				{
					school[s].stu.push_back(stu[i].index);
					break;
				}
			}
		}

		//打印
		for (i = 0; i < m; i++)
		{
			sort(school[i].stu.begin(), school[i].stu.end(), cmp1);
			for (j = 0; j < school[i].stu.size(); j++)
			{
				printf("%d", school[i].stu[j]);
				if (j != school[i].stu.size() - 1)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
