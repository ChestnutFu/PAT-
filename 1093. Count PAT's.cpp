#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	vector<int>p;
	vector<int>t;
	while (cin>>s)
	{
		int len = s.size();
		p.clear();
		p.resize(len);
		t.clear();
		t.resize(len);
		p[0] = s[0] == 'P' ? 1 : 0;
		t[0] = s[0] == 'T' ? 1 : 0;
		for (int i = 1; i < len; i++)
		{
			p[i] = p[i - 1];
			t[i] = t[i - 1];
			if (s[i] == 'P')
				p[i]++;
			if (s[i] == 'T')
				t[i]++;
		}
		long int total = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'A')
			{
				int num = p[i] * (t[len - 1] - t[i]);
				total += num;
			}
		}
		printf("%d\n", total % 1000000007);
	}
}
