#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;
vector<string>l;
bool compare(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		l.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> l[i];
		}
		sort(l.begin(), l.end(), compare);
		string s;
		for (int i = 0; i < n; i++)
		{
			s += l[i];
		}
		int x = -1;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] != '0')
			{
				x = i;
				break;
			}
		}
		if (x == -1)
			printf("0\n");
		else
		{
			for (int i = x; i < len; i++)
				printf("%c", s[i]);
			printf("\n");
		}

	}
	return 0;
}
