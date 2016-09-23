#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
struct node
{
	int val;
	int next;
};
int main()
{
	int head, n, k;
	while (scanf("%d%d%d", &head, &n, &k) != EOF)
	{
		node s[100000];
		map<int, int>ma;
		for (int i = 0; i < n; i++)
		{
			int address, data, next;
			scanf("%d%d%d", &address, &data, &next);
			s[address].val = data;
			s[address].next = next;
			ma[data] = address;
		}
		vector<int>l;
		int add = head;
		while (add!=-1)
		{
			l.push_back(s[add].val);
			add = s[add].next;
		}
		for (int i = 0; i + k - 1 < l.size(); i += k)
		{
			int j = i + k - 1;
			int r = i;
			while (r < j)
			{
				int x;
				x = l[r];
				l[r] = l[j];
				l[j] = x;
				r++;
				j--;
			}
		}
		for (int i = 0; i < l.size()-1; i++)
		{
			printf("%05d %d %05d\n", ma[l[i]], l[i], ma[l[i + 1]]);
		}
		printf("%05d %d -1\n", ma[l[l.size() - 1]], l[l.size() - 1]);
	}
	return 0;
}
