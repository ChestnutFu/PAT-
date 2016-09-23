#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXN 100000
using namespace std;
struct node
{
	int cnt;
	int index;
	node(int _cnt = 0, int _index = 0) :cnt(_cnt), index(_index){}
};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<node>list(MAXN + 1);
		int emp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &emp);
			list[emp].cnt++;
			list[emp].index = i;
		}
		int minIndex = n;
		int flag;
		for (int i = 0; i < (int)list.size(); i++)
		{
			if (list[i].cnt == 1)
			{
				if (minIndex>list[i].index)
				{
					minIndex = list[i].index;
					flag = i;
				}
			}
		}
		if (minIndex == n)
			printf("None\n");
		else
			printf("%d\n", flag);
	}
	return 0;
}
