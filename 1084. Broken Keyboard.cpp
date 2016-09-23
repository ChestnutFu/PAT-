#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
	string a, b;
	while (cin>>a>>b)
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] >= 'a'&&a[i] <= 'z')
			{
				a[i] = a[i] - ('a' - 'A');
			}
		}
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] >= 'a'&&b[i] <= 'z')
			{
				b[i] = b[i] - ('a' - 'A');
			}
		}
		map<char,int>s;
		map<char, int>::iterator it;
		int v = 0;
		int j = 0;
		while (v<a.length()&&j<b.length())
		{
			if (a[v] != b[j])
			{
				it = s.find(a[v]);
				if (it == s.end())
					printf("%c", a[v]);
				s[a[v]]++;
				v++;
			}
			else
			{
				v++;j++;
			}
		}
		while (v<a.length())
		{
			it = s.find(a[v]);
			if (it == s.end())
				printf("%c", a[v]);
			s[a[v]]++;
			v++;
		}

	}
	return 0;
}
