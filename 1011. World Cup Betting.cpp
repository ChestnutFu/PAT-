#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	char str[3] = { 'W', 'T', 'L' };
	float data[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &data[i][j]);
		}
	}
	float max, profit = 1;
	int m;
	for (i = 0; i < 3; i++)
	{
		max = data[i][0];
		m = 0;
		for (j = 1; j < 3; j++)
		{
			if (data[i][j] > max)
			{
				max = data[i][j];
				m = j;
			}
		}
		profit *= max;
		cout << str[m] << " ";
	}
	profit = (profit*0.65 - 1) * 2;
	printf("%.2f", profit);
	return 0;
}
