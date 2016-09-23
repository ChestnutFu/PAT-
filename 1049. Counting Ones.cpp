#include<iostream>
#include<stdio.h>
using namespace std;
int CountingOnes(int n)
{
	int count = 0;
	int factor = 1;
	int higher, lower, cur;
	while (n / factor != 0)
	{
		higher = n / (factor * 10);
		lower = n - (n / factor)*factor;
		cur = (n / factor) % 10;
		switch (cur)
		{
		case 0:
			count += higher*factor;
			break;
		case 1:
			count += higher*factor + lower + 1;
			break;
		default:
			count += (higher + 1)*factor;
			break;
		}
		factor *= 10;
	}
	return count;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", CountingOnes(n));
	}
	return 0;
}
