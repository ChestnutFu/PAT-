#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{

		int m;
		scanf("%d", &m);
		int eva[201];
		for (int i = 1; i <= m; i++)
			scanf("%d", &eva[i]);

		int l;
		scanf("%d", &l);
		int gives[10001];
		for (int i = 1; i <= l; i++)
			scanf("%d", &gives[i]);

		int temp[201][10001];
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= l; j++)
			{
				temp[i][j] = 0;
			}
		}

		int Ma;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= l; j++)
			{
				Ma = temp[i - 1][j - 1];
				if (Ma < temp[i][j - 1])Ma = temp[i][j - 1];
				if (Ma < temp[i - 1][j])Ma = temp[i - 1][j];
				if (eva[i] == gives[j])
					temp[i][j] = Ma + 1;
				else
					temp[i][j] = Ma;
			}
		}
		printf("%d\n", temp[m][l]);
	}
	return 0;
}
