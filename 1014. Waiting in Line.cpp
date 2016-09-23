#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct cus
{
	int proTime;
	int start;
	int leave;
};
int main()
{
	int n, m, k, q;
	while (scanf("%d%d%d%d", &n, &m, &k, &q) != EOF)
	{
		vector<cus>Cus(k + 1);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &Cus[i].proTime);
		}
		vector<queue<cus>>win(n);
		for (int i = 1; i <= n*m&&i <= k; i++)
		{
			int num = i%n;
			if (i <= n)
			{
				Cus[i].start = 8 * 60;
			}
			else
			{
				Cus[i].start = Cus[i - n].leave;
			}
			Cus[i].leave = Cus[i].start + Cus[i].proTime;
			win[num].push(Cus[i]);
		}
		for (int i = n*m + 1; i <= k; i++)
		{
			int minleave = 17 * 60 * 2, minwin;
			for (int j = 0; j < n; j++)
			{
				if (win[j].front().leave<minleave)
				{
					minleave = win[j].front().leave;
					minwin = j;
				}
			}

			Cus[i].start = win[minwin].back().leave;
			Cus[i].leave = Cus[i].proTime + Cus[i].start;
			win[minwin].pop();
			win[minwin].push(Cus[i]);
		}
		while (q--)
		{
			int Q;
			scanf("%d", &Q);
			if (Cus[Q].start<17*60)
			{
				printf("%02d:%02d\n", Cus[Q].leave / 60, Cus[Q].leave % 60);
			}
			else
			{
				printf("Sorry\n");
			}
		}
	}
	return 0;
}


