#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct node
{
	long int n;
	long int d;
};
long int getnum(long int a, long int b)
{
	if (a < 0)a*=-1;
	if (b < 0)b*=-1;
	long int min = a > b ? b : a;
	long int max = a > b ? a : b;
	if (min == 0)
		return 1;
	int x = max%min;
	while (x!=0)
	{
		max = x > min ? x : min;
		min = x > min ? min : x;

		x = max%min;
	}

	return min;
}
node getsum(node a, node b)
{
	node c;
	c.d = a.d*b.d;
	c.n = a.n*b.d + b.n*a.d;
	long int x = getnum(c.d, c.n);
	c.d /= x;
	c.n /= x;
	return c;
}
void printfnode(node a)
{
	if (a.n < 0)
	{
		printf("-");
		a.n *= -1;
	}
	long int x = 0;
	if (a.n > a.d)
	{
		x = a.n / a.d;
		a.n = a.n%a.d;
	}
	if (x != 0)
	{
		if (a.n != 0)
			printf("%ld %ld/%ld\n", x, a.n, a.d);
		else
			printf("%ld\n", x);
	}
	else
	{
		if (a.n == 0)
			printf("0\n");
		else
			printf("%ld/%ld\n", a.n, a.d);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		vector<node>l(n);
		for (int i = 0; i < n; i++)
		{
			long int a, b;
			scanf("%ld/%ld", &a, &b);
			long int c = getnum(a, b);
			l[i].n = a / c;
			l[i].d = b / c;
		}
		node x = l[0];
		for (int i = 1; i < n; i++)
		{
			x = getsum(x, l[i]);
		}
		printfnode(x);
	}
}
