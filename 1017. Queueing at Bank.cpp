#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct customer{
	int hou;
	int min;
	int sec;
	int pro;
	int arrTime;
	int startTime;
	int endTime;
};
struct windows
{
	int lastTime;
};
bool cmp(customer a,customer b)
{
	return a.arrTime < b.arrTime;
}

int main(){
	int n, k; 
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		int i;
		vector<customer>cus(n);
		for (i = 0; i < n;i++)
		{
			scanf("%d:%d:%d %d", &cus[i].hou, &cus[i].min, &cus[i].sec, &cus[i].pro);
			cus[i].arrTime = cus[i].sec + cus[i].min * 60 + cus[i].hou * 3600;
			cus[i].pro *= 60;
		}
		sort(cus.begin(), cus.end(), cmp);
		vector<windows>win(k);
		for (i = 0; i < k; i++)
			win[i].lastTime = 8 * 3600;
		int j;
		i = 0;
		while (i<n)
		{
			int min, minTime = 25 * 3600;
			for (j = 0; j < k; j++)
			{
				if (win[j].lastTime < minTime)
				{
					minTime = win[j].lastTime;
					min = j;
				}
			}
			if (cus[i].arrTime >= minTime)
			{
				cus[i].startTime = cus[i].arrTime;
				cus[i].endTime = cus[i].startTime + cus[i].pro;
				win[min].lastTime = cus[i].endTime;
			}
			else
			{
				cus[i].startTime = minTime;
				cus[i].endTime = cus[i].startTime + cus[i].pro;
				win[min].lastTime = cus[i].endTime;
			}
			i++;
		}
		int waitingTime = 0;
		int num = 0;
		for (i = 0; i < n; i++)
		{
			if (cus[i].arrTime <= 17 * 3600)
			{
				waitingTime += (cus[i].startTime - cus[i].arrTime);
				num++;
			}
		}
		double wait = (double)waitingTime / 60.0;
		double avg = (double)wait / (double)num;
		printf("%.1lf\n", avg);
	}
	return 0;
}
