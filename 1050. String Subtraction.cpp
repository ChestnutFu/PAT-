#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
int main()
{
	string s1;
	getline(cin, s1);
	map<char,int>s2;
	while (1)
	{
		char c = getchar();
		if (c == '\n')
			break;
		s2[c] = 1;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s2[s1[i]] != 1)
			printf("%c", s1[i]);
	}
	return 0;
}
