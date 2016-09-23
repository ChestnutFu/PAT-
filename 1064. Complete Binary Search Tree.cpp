#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int nodes[1001], tree[1001];
int pos, n;
bool cmp(int a,int b)
{
	return a < b;
}
void build(int root)
{
	if (root > n)
		return;
	int left = root * 2, right = root * 2 + 1;

	build(left);
	tree[root] = nodes[pos++];
	build(right);
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &nodes[i]);
		sort(nodes, nodes + n, cmp);
		pos = 0;

		build(1);
		for (i = 1; i <= n; i++)
		{
			printf("%d%c", tree[i], n - i ? ' ' : '\n');
		}
	}
	return 0;
}
