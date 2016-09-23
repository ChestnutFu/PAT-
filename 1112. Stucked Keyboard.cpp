#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int k;
	while (scanf("%d",&k)!=EOF)
	{
		string s;
		cin >> s;
		vector<char>stuck;
		vector<vector<int>>chars(256);
		int i, j;
		for (i = 0; i < s.length(); i = j)
		{
			for (j = i; j < s.length(); j++)
			{
				if (s[j] != s[i])
					break;
			}
			chars[s[i]].push_back(j - i);
		}
		for (i = 0; i < s.length(); i++)
		{
			j = 0;
			for (; j < chars[s[i]].size(); j++)
			{
				if (chars[s[i]][j] % k != 0)
					break;
			}
			if (j == chars[s[i]].size())
			{
				stuck.push_back(s[i]);
				chars[s[i]].clear();
				chars[s[i]].push_back(1);
			}
		}
		for (i = 0; i < stuck.size(); i++)
		{
			cout << stuck[i];
			for (j = 0; j < s.length(); j++)
			{
				if (s[j] == stuck[i])
				{
					s.erase(j, k - 1);
				}
			}
		}
		cout << endl << s << endl;
	}
	return 0;
}
