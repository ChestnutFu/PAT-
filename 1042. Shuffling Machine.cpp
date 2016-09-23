#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
void printfint(int x)
{
	int s = x / 13;
	int n = x % 13;
	if (n == 0)
		s--;
	switch (s)
	{
	case 0:
		printf("S");
		break;
	case 1:
		printf("H");
		break;
	case 2:
		printf("C");
		break;
	case 3:
		printf("D");
		break;
	case 4:
		printf("J");
		break;
	default:
		break;
	}
	if (n == 0)
	{
		printf("13");
	}
	else
	{
		printf("%d", n);
	}
}
int main()
{
	int k;
	int cards[55];
	for (int i = 1; i <= 54; i++)
	{
		cards[i] = i;
	}
	while (scanf("%d", &k) != EOF)
	{
		int shuff[55];
		for (int i = 1; i <= 54; i++)
		{
			int x;
			scanf("%d", &x);
			shuff[i] = x;
		}
		int cards1[55];
		while (k--)
		{
			for (int i = 1; i <= 54; i++)
			{
				cards1[i] = cards[i];
			}
			for (int i = 1; i <= 54; i++)
			{
				cards[shuff[i]] = cards1[i];
			}
		}
		for (int i = 1; i <= 54; i++)
		{
			if (i == 1)
			{
				printfint(cards[i]);
			}
			else
			{
				printf(" ");
				printfint(cards[i]);
			}
		}
	}
	return 0;
}
