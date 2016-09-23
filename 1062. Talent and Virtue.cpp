#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;//(<= 105), the total number of people to be ranked;
int l;//(>=60), the lower bound of the qualified grades
int h;// (<100), the higher line of qualification
struct node
{
	int id;
	int virtue;
	int talent;
	int total;
};
vector<node>sages;
vector<node>noblemen;
vector<node>foolman;
vector<node>rest;
bool cmp(node a,node b)
{
	if (a.total == b.total)
	{
		if (a.virtue == b.virtue)
			return a.id < b.id;
		else
			return a.virtue > b.virtue;
	}
	else
		return a.total > b.total;
}
int main()
{
	while (scanf("%d%d%d", &n, &l, &h) != EOF)
	{
		int id, virtue, talent;
		node a;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &id, &virtue, &talent);
			if (virtue >= l&&talent >= l)
			{
				k++;
				a.id = id; a.virtue = virtue; a.talent = talent;
				a.total = virtue + talent;
				if (virtue >= h&&talent >= h)
					sages.push_back(a);
				else if (virtue >= h&&talent < h)
					noblemen.push_back(a);
				else if (virtue < h&&talent < h&&virtue >= talent)
					foolman.push_back(a);
				else
					rest.push_back(a);
			}
		}
		sort(sages.begin(), sages.end(), cmp);
		sort(noblemen.begin(), noblemen.end(), cmp);
		sort(foolman.begin(), foolman.end(), cmp);
		sort(rest.begin(), rest.end(), cmp);
		printf("%d\n", k);
		for (int i = 0; i < sages.size(); i++)
			printf("%d %d %d\n", sages[i].id, sages[i].virtue, sages[i].talent);
		for (int i = 0; i < noblemen.size(); i++)
			printf("%d %d %d\n", noblemen[i].id, noblemen[i].virtue, noblemen[i].talent);
		for (int i = 0; i < foolman.size(); i++)
			printf("%d %d %d\n", foolman[i].id, foolman[i].virtue, foolman[i].talent);
		for (int i = 0; i < rest.size(); i++)
			printf("%d %d %d\n", rest[i].id, rest[i].virtue, rest[i].talent);
	}
	return 0;
}
