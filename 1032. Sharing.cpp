#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int map[100001];
	bool flag[100001];
	int N;
	int add1, add2;
	while (scanf("%d%d%d", &add1, &add2, &N) != EOF)
	{

		int i;
		int address, next;
		char data;
		for (i = 0; i < 100001; i++)
		{
			flag[i] = false;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%d%*c%c%d", &address, &data, &next);
			map[address] = next;
		}
		int x = add1;
		while (x != -1)
		{
			flag[x] = true;
			x = map[x];
		}
		x = add2;
		while (x != -1)
		{
			if (flag[x])
				break;
			x = map[x];
		}
		if (x == -1)
			printf("%d", x);
		else
			printf("%.5d", x);
	}
	return 0;
}
