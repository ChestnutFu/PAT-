#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
bool IsPrime(long int n)
{
	if (n == 2)
		return true;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	long int n;
	while (scanf("%ld", &n) != EOF)
	{
		printf("%ld=", n);
		if (n == 1)
		{
			printf("%ld\n", n);
			continue;
		}
		int i;
		int temp = n;
		for (int i = 2; temp > 1 && i <= temp; i++)
		{ 
			int k = 0;
			if (IsPrime(i))
			{
				while (temp%i==0)
				{
					k++;
					temp /= i;
				}
				if (k > 1)
				{
					printf("%d^%d", i, k);
				}
				else if (k == 1)
					printf("%d", i);
				if (k != 0 && temp != 1)
					printf("*");
				else if (k != 0 && temp == 1)
					printf("\n");
			}
		}
	}
	return 0;
}
