#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<stack>
using namespace std;
struct node
{
	int val;
	int next;
};
struct anode
{
	int add;
	int val;
};

int main()
{
	int n;
	int head;
	while (scanf("%d%d",&head,&n)!=EOF)
	{
		map<int, node>L;
		int i = 0;
		int add, val, next;
		vector<int>times(100000, 0);
		for (; i < n; i++)
		{
			scanf("%d%d%d", &add, &val, &next);
			L[add].val = val;
			L[add].next = next;
		}
		vector<anode>result;
		vector<anode>remove;
		int h = head;
		while (h!=-1)
		{
			anode a;
			a.val = L[h].val;
			a.add = h;

			int val = a.val;
			if (val < 0)
				val *= -1;

			if (times[val] == 0)
			{
				result.push_back(a);
				times[val]++;
			}
			else
			{
				remove.push_back(a);
				times[val]++;
			}

			h = L[h].next;
		}

		for (i = 0; i < result.size() - 1; i++)
			printf("%05d %d %05d\n", result[i].add, result[i].val, result[i + 1].add);
		printf("%05d %d -1\n", result[i].add, result[i].val);
		if (remove.size()!=0)
		{
			for (i = 0; i < remove.size() - 1; i++)
				printf("%05d %d %05d\n", remove[i].add, remove[i].val, remove[i + 1].add);
			printf("%05d %d -1\n", remove[i].add, remove[i].val);
		}
	}
	return 0;
}
