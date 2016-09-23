#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
struct node
{
	int index;
	double val;
};
int main()
{
	vector<double>list(1001, 0);
	int n1, n2;
	scanf("%d", &n1);
	int nk;
	double a;
	while(n1--)
	{
		scanf("%d%lf", &nk, &a);
		list[nk] += a;
	}
	scanf("%d", &n2);
	while (n2--)
	{
		scanf("%d%lf", &nk, &a);
		list[nk] += a;
	}
	vector<node>l;
	node b;
	for (int i = 0; i <= 1000; i++)
	{
		if (list[i] != 0)
		{
			b.index = i;
			b.val = list[i];
			l.push_back(b);
		}
	}
	printf("%d", l.size());
	for (int i = l.size() - 1; i >= 0; i--)
	{
		printf(" %d %.1lf", l[i].index, l[i].val);
	}
	system("pause");
	return 0;
}
