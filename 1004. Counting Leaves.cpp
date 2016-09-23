#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int id;
	int k;
	vector<int>child;
	int level;
};
int main()
{
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		vector<node>tree(N+1);
		int i;
		int id, k, child_id;
		for (i = 0; i < M; i++)
		{
			scanf("%d%d", &id, &k);
			tree[id].id = id;
			if (k != 0)
			{
				tree[id].k = k;
				while (k--)
				{
					scanf("%d", &child_id);
					tree[id].child.push_back(child_id);
				}
			}
			else
				tree[id].k = 0;
		}
		vector<int>levels(N);
		int maxlevel = 0;
		queue<int>q;
		q.push(1);
		tree[i].level = 0;
		if (tree[1].k == 0)
		{
			levels[0]++;
		}
		while (!q.empty())
		{
			int root = q.front();
			q.pop();
			if (tree[root].k)
			{
				for (int i = 0; i < tree[root].k; i++)
				{
					int child = tree[root].child[i];
					q.push(child);
					tree[child].level = tree[root].level + 1;
					if (tree[child].level > maxlevel)
						maxlevel = tree[child].level;
					if (tree[child].k > 0)
					{
						continue;
					}
					else
					{
						levels[tree[child].level]++;
					}
				}
			}
		}
		for (int i = 0; i <= maxlevel; i++)
		{
			printf("%d", levels[i]);
			if (i != maxlevel)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
