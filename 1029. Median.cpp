#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<long int>l1, l2;
	int k1, k2;
	scanf("%d", &k1);
	l1.resize(k1);
	for (int i = 0; i < k1; i++)
		scanf("%ld", &l1[i]);

	scanf("%d", &k2);
	l2.resize(k2);
	for (int i = 0; i < k2; i++)
		scanf("%ld", &l2[i]);

	vector<long int>l;

	int p1 = 0; 
	int p2 = 0;
	while (1)
	{
		if (p1 == k1&&p2 == k2)
			break;
		if (p1 < k1 && p2 < k2)
		{
			if (l1[p1] <= l2[p2])
			{
				l.push_back(l1[p1]);
				p1++;
			}
			else
			{
				l.push_back(l2[p2]);
				p2++;
			}
		}
		else if (p2 == k2&&p1 < k1)
		{
			l.push_back(l1[p1]);
			p1++;
		}
		else if (p1 == k1&&p2 < k2)
		{
			l.push_back(l2[p2]);
			p2++;
		}
	}
	int n = (int)l.size();
	n = (n - 1) / 2;
	printf("%ld\n", l[n]);
	system("pause");
	return 0;
}
