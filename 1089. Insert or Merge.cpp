#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool isOrder(vector<int>s,int start,int n)
{
	for (int i = start; i < n - 1; i++)
	{
		if (s[i]>s[i + 1])
			return false;
	}
	return true;
}
int findLength(vector<int>s)
{
	int len = 1, i;
	bool flag = true;
	while (len<=s.size())
	{
		for (i = 0; i + 2 * len <= s.size(); i += 2 * len)
		{
			if (!isOrder(s, i, i + 2 * len - 1))
				flag = false;
		}
		if (i < s.size() - 1)
		{
			if (!isOrder(s, i, s.size() - 1))
				flag = false;
		}
		if (flag == false)
			return len;
		else
			len *= 2;
	}
}
void MergeSort(vector<int>&a,vector<int>&b,int l,int r,int rightEnd)
{
	int tmp = l;
	int leftEnd = r - 1;
	int len = rightEnd - l + 1;
	while (l<=leftEnd&&r<=rightEnd)
	{
		if (a[l] <= a[r])b[tmp++] = a[l++];
		else b[tmp++] = a[r++];
	}
	while (l <= leftEnd)b[tmp++] = a[l++];
	while (r <= rightEnd)b[tmp++] = a[r++];
	for (int i = 0; i < len; i++, rightEnd--)
		a[rightEnd] = b[rightEnd];
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		vector<int>s(n), s1(n);
		for (i = 0; i < n; i++)
			scanf("%d", &s[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &s1[i]);

		bool flag = true;
		int mark;
		for (i = 1; i < n; i++)
		{
			if (s1[i] < s1[i - 1])
			{
				mark = i;
				break;
			}
		}
		for (i = mark; i < n; i++)
		{
			if (s[i] != s1[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("Insertion Sort\n");
			int x = s1[mark];
			for (i = mark; i > 0 && s1[i - 1] > x; i--)
				s1[i] = s1[i - 1];
			s1[i] = x;
		}
		else
		{
			printf("Merge Sort\n");
			int len = findLength(s1);
			vector<int>s2(n);
			for (i = 0; i + 2 * len <= s1.size(); i += 2*len)
			{
				MergeSort(s1, s2, i, i + len, i + 2 * len - 1);
			}
			if (i +len< s1.size())
			{
				MergeSort(s1, s2, i, i + len, s1.size() - 1);
			}
		}
		for (i = 0; i < n; i++)
			printf("%d%c", s1[i], n - 1 - i ? ' ' : '\n');
	}
	return 0;
}
