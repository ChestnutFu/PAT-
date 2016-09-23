#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	double p;
	double dis;

	node(double _p, double _dis)
	{
		p = _p;
		dis = _dis;

	}
};
bool cmp(node a,node b)
{
	return a.dis < b.dis;
}
int main()
{
	double cmax; //<= 100, the maximum capacity of the tank;
	double d;//<=30000, the distance between Hangzhou and the destination city
	double davg;//<=20, the average distance per unit gas that the car can run
	int n;//<= 500, the total number of gas stations

	while (scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n) != EOF)
	{
		vector<node>gas;
		for (int i = 0; i < n;i++)
		{
			double p, dis;
			scanf("%lf%lf", &p, &dis);
			gas.push_back(node(p, dis));
		}
		gas.push_back(node(0, d));
		sort(gas.begin(), gas.end(), cmp);
		double totalP = 0;
		int i = 0;
		double canMaxDis = davg*cmax;
		double gasInCar = 0;
		double nextRunDis;
		while (1)
		{
			if (i == n)
				break;
			//如果起点没有加油站
			if (i == 0 && gas[0].dis != 0)
			{
				printf("The maximum travel distance = 0.00\n");
				break;
			}

			double minNextP = 9999.00;
			int min = -1;
			//找这个加油站接下来能达到的最大距离中的加油站
			for (int j = i + 1; j <= n; j++)
			{
				if (gas[i].dis + canMaxDis < gas[j].dis)
					break;
				if (gas[j].p < gas[i].p)
				{
					min = j;
					break;
				}
				if (gas[j].p < minNextP)
				{
					min = j;
					minNextP = gas[j].p;
				}
			}
			//如果在接下来的路程里没有找到
			if (min == -1)
			{
				printf("The maximum travel distance = %.2lf\n", gas[i].dis + canMaxDis);
				break;
			}
			else
			{
				if (gas[min].p <= gas[i].p)
				{//如果下面的路程有比这个加油站小的
					//加油加到刚刚能到达下个加油站
					if (gasInCar*davg < (gas[min].dis - gas[i].dis))
					{
						double gg = (gas[min].dis - gas[i].dis) / davg;
						totalP += (gg - gasInCar)*gas[i].p;
						gasInCar = gg;
					}
				}
				else if (gas[min].p>gas[i].p)
				{//如果接下来的加油站钱都比现在的这个大
					//把油加满
					totalP += (cmax - gasInCar)*gas[i].p;
					gasInCar = cmax;
				}

				gasInCar = gasInCar - (gas[min].dis - gas[i].dis) / davg;
				i = min;
			}
		}
		if (i == n)
			printf("%.2lf\n", totalP);
	}
	return 0;
}
