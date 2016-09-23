#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		getchar();
		string s, str;
		getline(cin, s);
		n--;
		while (n--)
		{
			getline(cin, str);
			int a = s.length() - 1;
			int b = str.length() - 1;
			while (a>=0&&b>=0&&s[a]==str[b])
			{
				a--; b--;
			}
			a++;
			if (s.length() - a == 0)
				s = "nai";
			else if (s!="nai")
			{
				s = s.substr(a);
			}
		}
		cout << s << endl;
	}
	return 0;
}
