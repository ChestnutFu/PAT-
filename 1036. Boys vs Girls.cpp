#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	char gender;
	string id;
	int grade;
};
vector<node>student;
bool fcmp(node a,node b)
{
	return a.grade > b.grade;
}
bool mcmp(node a,node b)
{
	return a.grade < b.grade;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		student.resize(n);
		vector<node>male;
		vector<node>famale;
		for (int i = 0; i < n; i++)
		{
			cin >> student[i].name >> student[i].gender >> student[i].id >> student[i].grade;
			if (student[i].gender == 'M')
			{
				male.push_back(student[i]);
			}
			else
			{
				famale.push_back(student[i]);
			}
		}
		if (male.empty())
		{
			sort(famale.begin(), famale.end(), fcmp);
			cout << famale[0].name << " " << famale[0].id << endl;
			printf("Absent\n");
			printf("NA\n");
		}
		else if (famale.empty())
		{
			sort(male.begin(), male.end(), mcmp);
			printf("Absent\n");
			cout << male[0].name << " " << male[0].id << endl;
			printf("NA\n");
		}
		else
		{
			sort(famale.begin(), famale.end(), fcmp);
			sort(male.begin(), male.end(), mcmp);
			cout << famale[0].name << " " << famale[0].id << endl;
			cout << male[0].name << " " << male[0].id << endl;
			int d = famale[0].grade - male[0].grade;
			printf("%d\n", d);
		}

	}
	return 0;
}
