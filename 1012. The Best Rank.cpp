#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
struct student_node{
	string student_ID;
	int grades[4];
};
typedef struct student_node student;

int find_rank(vector<student> &Stu,int N,int grade,int the_class)
{
	int rank = 1;
	//the_class是要找的课程
	int i;
	for (i = 0; i < N; i++)
	{
		if (Stu[i].grades[the_class] > grade)
			rank++;
	}
	return rank;
}
int main()
{
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF)
	{
		int i;
		vector<student> Stu(N);
		for (i = 0; i < N; i++)
		{
			cin >> Stu[i].student_ID;
			scanf("%d%d%d", &Stu[i].grades[1], &Stu[i].grades[2], &Stu[i].grades[3]);
			Stu[i].grades[0] = (Stu[i].grades[1] + Stu[i].grades[2] + Stu[i].grades[3]) / 3;
		}
		int j;
		int min_rank, min;
		int k;
		char classes[4] = { 'A', 'C', 'M', 'E' };
		for (i = 0; i < M; i++)
		{
			bool flag = false;
			string str;
			cin >> str;
			for (j = 0; j < N; j++)
			{
				if (str == Stu[j].student_ID)
				{
					min_rank = N + 1;
					for (k = 0; k < 4; k++)
					{
						if (min_rank>find_rank(Stu, N, Stu[j].grades[k], k))
						{
							min_rank = find_rank(Stu, N, Stu[j].grades[k], k);
							min = k;
						}
					}
					flag = true;
				}
			}	
			if (flag)
			{
				cout << min_rank << " " << classes[min] << endl;
			}
			else
			{
				printf("N/A\n");
			}
		}
	}
	return 0;
}
