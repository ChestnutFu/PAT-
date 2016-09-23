#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		int len = s.size();
		int n1, n2;
		int mn1 = 0;
		for (n2 = 3; n2 <= len; n2++)
		{
			int temp = len + 2 - n2;
			n1 = temp / 2;
			if (n1 > n2)
				continue;
			if (mn1 < n1)
				mn1 = n1;
		}
		int i;
		n2 = len - 2 * mn1 + 2;
		for (i = 0; i < mn1 - 1; i++)
		{
			cout << s[i];
			for (int j = 0; j < n2 - 2; j++)
			{
				cout << " ";
			}
			cout << s[len - 1 - i] << endl;
		}
		for (; i <= len - mn1; i++)
			cout << s[i];
	}
	return 0;
}
