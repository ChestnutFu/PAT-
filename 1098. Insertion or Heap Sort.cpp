#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
void swap(int &a,int &b)
{
	int c = a;
	a = b;
	b = c;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int>s1(n), s2(n);
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &s1[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &s2[i]);
		int mark;//第一个不同的位置
		for (i = 1; i < n ; i++)
		{
			if (s2[i - 1] > s2[i])
			{
				mark = i;
				break;
			}
		}
		bool flag = true;
		for (i = mark; i < n; i++)
		{
			if (s1[i]!=s2[i])
			{
				flag = false;//堆排序
				break;
			}
		}

		if (flag)
		{
			printf("Insertion Sort\n");
			int tmp = s2[mark];
			for (i = mark; i > 0 && s2[i - 1] > tmp; i--)
				s2[i] = s2[i - 1];
			s2[i] = tmp;
			for (i = 0; i < n; i++)
				printf("%d%c", s2[i], n - 1 - i ? ' ' : '\n');
		}
		else
		{
			printf("Heap Sort\n");
			for (i = n - 1; i > 0; i--)
			{
				if (s2[i - 1] > s2[i])
				{
					mark = i;
					break;
				}
			}
			swap(s2[0], s2[mark]);
			int x = s2[0];
			int parent = 0, child;
			for (; parent * 2 + 1 < mark; parent = child)
			{
				child = parent * 2 + 1;
				if (child != mark - 1 && s2[child] < s2[child + 1])
					child++;
				if (s2[child] <= x)
					break;
				else
					s2[parent] = s2[child];
			}
			s2[parent] = x;
			for (i = 0; i < n; i++)
				printf("%d%c", s2[i], n - 1 - i ? ' ' : '\n');
		}
	}
	return 0;
}
