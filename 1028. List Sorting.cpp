#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int id;
	char name[20];
	int grade;
};
//C = 1 then the records must be sorted in increasing order according to ID's
bool Cmp1(node a,node b)
{
	return a.id < b.id;
}
// C = 2 then the records must be sorted in non-decreasing order according to names
bool Cmp2(node a, node b)
{
	if (strcmp(a.name, b.name)==0)
		return a.id < b.id;
	else
		return strcmp(a.name, b.name) < 0;
}
//C = 3 then the records must be sorted in non-decreasing order according to grades.
//If there are several students who have the same name or grade,
// they must be sorted according to their ID's in increasing order.
bool Cmp3(node a, node b)
{
	if (a.grade == b.grade)
		return a.id < b.id;
	else
		return a.grade < b.grade;
}
int main()
{
	int N;//N is the number of records
	int C;// C is the column that you are supposed to sort the records with
	vector<node>students;
	while (scanf("%d%d",&N,&C)!=EOF)
	{
		students.resize(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d%s%d", &students[i].id, &students[i].name, &students[i].grade);
		}
		switch (C)
		{
		case 1:
			sort(students.begin(), students.end(), Cmp1);
			break;
		case 2:
			sort(students.begin(), students.end(), Cmp2);
			break;
		case 3:
			sort(students.begin(), students.end(), Cmp3);
			break;
		default:
			break;
		}
		for (int i = 0; i < N; i++)
		{
			printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
		}
	}
}
