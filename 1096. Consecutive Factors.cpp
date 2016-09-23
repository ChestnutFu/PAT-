#include<iostream>
#include<stdio.h>
using namespace std;

bool IsPrime(long long int n)
{
	if (n == 2 || n == 3)
		return true;
	else
	{
		for (long long int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
				return false;
		}
	}
	return true;
}
void find(long long int n,long long int &start,long long int &len)
{
	long long int x, i, j;
	for (i = 2; i <= n; i++)
	{
		x = i;
		if (n%x == 0&&len==0&&start==-1)
			start = i;
		for (j = 1; j <= 31; j++)
		{
			x *= (i + j);
			if (n%x==0)
			{
				if (j > len)
				{
					len = j;
					start = i;
				}
			}
			if (x > n)
				break;
		}
	}
}
int main()
{
	long long int n;

	while (scanf("%lld",&n)!=EOF)
	{
		long long int start = -1, len = 0;
		if (IsPrime(n))
			printf("1\n%lld\n", n);
		else
		{
			find(n,start,len);
			printf("%lld\n", len + 1);
			for (long long int i = 0; i <= len; i++)
			{
				printf("%lld%c", start + i, len - i ? '*' : '\n');
			}
		}
	}
	return 0;
}
