#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int w[1001];
int ans[1001];
int main()
{
	int np, ng;
	//np:the number of programmers
	//ng:the maximum number of mice in a group
	while (scanf("%d%d",&np,&ng)!=EOF)
	{
		for (int i = 0; i < np; i++)
			scanf("%d", &w[i]);
		queue<int>order;
		for (int i = 0; i < np; i++)
		{
			int temp;
			scanf("%d", &temp);
			order.push(temp);
		}
		while (order.size()!=1)
		{
			int groupNum = order.size() / ng;
			if (order.size()%ng != 0)
				groupNum++;
			queue<int>q;
			for (int i = 0; i < groupNum; i++)
			{
				int max = -1, maxIndex = -1;
				for (int j = ng*i; j < ng*(i + 1) && order.size() != 0; j++)
				{
					int x = order.front();
					ans[x] = groupNum + 1;
					order.pop();
					if (w[x] > max)
					{
						max = w[x];
						maxIndex = x;
					}
					
				}
				q.push(maxIndex);
			}
			order = q;
		}
		ans[order.front()] = 1;
		for (int i = 0; i < np; i++)
		{
			printf("%d", ans[i]);
			if (i == np - 1)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
