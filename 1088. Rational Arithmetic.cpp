#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct node
{
	long int a;
	long int b;
};
long int getnum(string s)
{
	long int x = 0;
	long int m = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		x += (s[i] - '0')*m;
		m *= 10;
	}
	return x;
}
node findnode(string s)
{
	node a;
	int index = s.find("/");
	string m, h;
	if (s[0] == '-')
	{
		m = s.substr(1, index - 1);
		a.a = getnum(m)*-1;
	}
	else
	{
		m = s.substr(0, index);
		a.a = getnum(m);
	}
	h = s.substr(index + 1);
	a.b = getnum(h);
	return a;
}
char cus[4] = { '+', '-', '*', '/' };
long int findcmp(long int a,long int b)
{
	long long int max, min, c, r;
	max = a > b ? a : b;
	min = a > b ? b : a;
	while (1)
	{
		c = max%min;
		if (c == 0)
		{
			r = min;
			break;
		}
		else
		{
			max = min;
			min = c;
		}
	}
	return r;
}
void printfnode(node a)
{
	int ax;
	if ((a.a > 0 && a.b < 0) || (a.a < 0 && a.b>0))
		ax = -1;
	else
		ax = 1;
	if (a.a == 0)
	{
		printf("0");
		return;
	}
	if (ax < 0)
		printf("(-");

	if (a.a < 0)
		a.a *= -1;
	if (a.b < 0)
		a.b *= -1;

	long int D = a.a / a.b;
	long int d = a.a%a.b;
	if (D != 0)
		cout << D;
	if (D != 0 && d != 0)
		printf(" ");
	if (d != 0)
	{
		long int cc = findcmp(d, a.b);
		printf("%ld/%ld",d/cc,a.b/cc);
	}

	if (ax < 0)
		printf(")");
}
node calc(node a, node b, int v)
{
	node c;

	if (v == 0)
	{
		c.b = a.b*b.b;
		c.a = a.a*b.b + b.a*a.b;
	}
	else if (v == 1)
	{
		c.b = a.b*b.b;
		c.a = a.a*b.b - b.a*a.b;
	}
	else if (v == 2)
	{
		c.a = a.a*b.a;
		c.b = a.b*b.b;
	}
	else if (v == 3)
	{
		c.a = a.a*b.b;
		c.b = a.b*b.a;
	}
	return c;
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		node a1, a2;
		a1 = findnode(a);
		a2 = findnode(b);
		for (int i = 0; i < 4; i++)
		{
			printfnode(a1);
			printf(" %c ", cus[i]);
			printfnode(a2);
			printf(" = ");
			node c = calc(a1, a2, i);
			if (i == 3 && c.b == 0)
				printf("Inf");
			else
				printfnode(c);
			printf("\n");
		}
	}
	return 0;
}
