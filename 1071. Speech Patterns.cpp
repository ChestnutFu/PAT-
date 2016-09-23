#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main()
{
	char c;
	map<string, int>m;
	vector<char>input;
	int maxx = 0;
	while (scanf("%c", &c) && c != '\n')
	{
		if (c>='A'&&c<='Z')
		{
			c = c + ('a' - 'A');
			input.push_back(c);
		}
		else if (c >= 'a'&&c <= 'z')
		{
			input.push_back(c);
		}
		else if (c >= '0'&&c <= '9')
		{
			input.push_back(c);
		}
		else
		{
			vector<char>::iterator it = input.begin();
			int len = input.size();
			if (len != 0)
			{
				string s(it, it + len);
				m[s]++;
				if (m[s] > maxx)
					maxx = m[s];
				input.clear();
			}
		}
	}
	if (!input.empty())
	{
		vector<char>::iterator it = input.begin();
		int len = input.size();
		string s(it, it + len);
		m[s]++;
		if (m[s] > maxx)
			maxx = m[s];
		input.clear();
	}
	map<string, int>::iterator itm = m.begin();
	
	for (; itm != m.end(); itm++)
	{
		if (itm->second == maxx)
		{
			cout << itm->first << " " << itm->second << endl;
			break;
		}
	}
	return 0;
}
