#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	set<int>rest;
	int estate;//total number of sets of the real estate under his/her name
	int area;//is the total area of his/her estate.
	node():estate(0),area(0){}
};
node p[10001];
bool isvis[10001];

struct res_data
{
	int id;
	int num;
	double avg_estate;
	double avg_area;
	res_data(int i, int n, double ae, double aa) :id(i), num(n), avg_estate(ae), avg_area(aa){}
};
void dfs(int id, int &min_id, int &num, int &sum_estate, int &sum_area)
{
	if (id == -1 || isvis[id])
		return;
	min_id = min(min_id, id);
	num++;
	sum_estate += p[id].estate;
	sum_area += p[id].area;
	isvis[id] = true;

	set<int>::iterator it;
	for (it = p[id].rest.begin(); it != p[id].rest.end(); it++)
	{
		dfs(*it, min_id, num, sum_estate, sum_area);
	}
}
bool cmp(const res_data &r1, const res_data &r2)
{
	if (r1.avg_area != r2.avg_area)
		return r1.avg_area > r2.avg_area;
	else
		return r1.id < r2.id;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		memset(isvis, false, sizeof(isvis));
		vector<int>ids(n);
		for (int i = 0; i < n;i++)
		{
			int id, f, m, k;
			scanf("%d%d%d%d", &id, &f, &m, &k);
			ids[i] = id;
			if (f != -1)
			{
				p[id].rest.insert(f);
				p[f].rest.insert(id);
			}
			if (m != -1)
			{
				p[id].rest.insert(m);
				p[m].rest.insert(id);
			}
			for (int j = 0; j < k; j++)
			{
				int c;
				scanf("%d", &c);
				p[id].rest.insert(c);
				p[c].rest.insert(id);
			}
			scanf("%d%d", &p[id].estate, &p[id].area);
		}

		vector<res_data>res;
		for (int i = 0; i < n; i++)
		{
			if (isvis[ids[i]])
				continue;
			int min_id = 1 << 30, num = 0, sum_estate = 0, sum_area = 0;
			dfs(ids[i], min_id, num, sum_estate, sum_area);
			res.push_back(res_data(min_id, num, double(sum_estate*1.0 / num), double(sum_area*1.0 / num)));
		}
		sort(res.begin(), res.end(), cmp);
		cout << res.size() << endl;
		for (int i = 0; i<res.size(); i++)
		{
			printf("%04d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].avg_estate, res[i].avg_area);
		}
	}
}
