#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int List[101];
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &List[i]);
		}

		int elevator = 0;
		int change, time = 0;

		for (i = 0; i < N; i++)
		{
			change = List[i] - elevator;
			if (change >= 0)
			{
				time = time + change * 6;
			}
			else 
			{
				time = time - change * 4;
			}
			time += 5;
			elevator = List[i];
		}
		printf("%d", time);
	}
	return 0;
}
