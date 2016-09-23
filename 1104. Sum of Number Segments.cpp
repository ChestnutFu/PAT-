#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		double sum = 0.0, num;
		int i;
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &num);
			sum += num*(i + 1)*(n - i);
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
