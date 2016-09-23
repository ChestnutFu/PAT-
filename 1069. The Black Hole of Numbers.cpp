#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int N, max, min;
		int time = 0;
		while (1)
		{
			int l[4];
			l[0] = n / 1000;
			l[1] = n / 100 - l[0] * 10;
			l[2] = (n % 100) / 10;
			l[3] = n % 10;
			int x;
			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					if (l[i] < l[j])
					{
						x = l[j];
						l[j] = l[i];
						l[i] = x;
					}
				}
			}
			max = l[0] * 1000 + l[1] * 100 + l[2] * 10 + l[3];
			min = l[3] * 1000 + l[2] * 100 + l[1] * 10 + l[0];
			N = max - min;
			if (N != n||(N==n&&time==0))
			{
				printf("%04d - %04d = %04d\n", max, min, N);
				time++;
			}
			else
				break;
			n = N;
		}
	}
	return 0;
}
