#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(node a,node b)
{
	return a.grade > b.grade;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		vector<node>stu(n);
		for (int i = 0; i < n;i++)
		{
			scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].grade);
		}
		int grade1, grade2;
		scanf("%d%d", &grade1, &grade2);
		vector<node>Stu;
		for (int i = 0; i < n; i++)
		{
			if (stu[i].grade >= grade1&&stu[i].grade <= grade2)
			{
				Stu.push_back(stu[i]);
			}
		}
		if (Stu.empty())
			printf("NONE\n");
		else
		{
			sort(Stu.begin(), Stu.end(), cmp);
			for (int i = 0; i < Stu.size(); i++)
			{
				printf("%s %s\n", Stu[i].name, Stu[i].id);
			}
		}
	}
	return 0;
}
