#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int add;
	int val;
	int next;
};
bool cmp(node a, node b)
{
	return a.val < b.val;
}
node a[100000];
int n, head;
int main()
{
	while (scanf("%d%d",&n,&head)!=EOF)
	{
		while (n--)
		{
			int add, val, next;
			scanf("%d%d%d", &add, &val, &next);
			a[add].add = add;
			a[add].val = val;
			a[add].next = next;
		}
		vector<node>l;
		int h = head;
		if (h == -1)
		{
			printf("0 -1\n");
			continue;
		}
		while (h!=-1)
		{
			node x = a[h];
			l.push_back(x);
			h = a[h].next;
		}
		sort(l.begin(), l.end(), cmp);
		printf("%d %05d\n", l.size(), l[0].add);
		if (l.size() != 0)
		{
			for (int i = 0; i < l.size() - 1; i++)
				printf("%05d %d %05d\n", l[i].add, l[i].val, l[i + 1].add);
			printf("%05d %d -1\n", l[l.size() - 1].add, l[l.size() - 1].val);
		}
	}
	return 0;
}
