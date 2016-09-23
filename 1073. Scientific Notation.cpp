#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	while (cin>>s)
	{
		string ans = "";
		int Eindex = s.find("E");
		if (s[0] == '-')
			ans += s[0];
		string num= s.substr(1, Eindex - 1);
		
		char p = s[Eindex + 1];

		stringstream ss;
		string exp= s.substr(Eindex + 2, s.length() - Eindex - 1);
		int e;
		ss << exp;
		ss >> e;


		if (e == 0)
		{
			cout << ans << num << endl;
		}
		else
		{
			if (p == '+')
			{
				if (e < num.size() - 2)
				{
					ans = ans + num[0] + num.substr(2, e) + "." + num.substr(e + 2);
				}
				else
				{
					ans = ans + num[0] + num.substr(2);
					for (int i = 0; i < e - num.size() + 2; i++)
						ans += "0";
				}
			}
			else if (p == '-')
			{
				ans = ans + "0.";
				while (e--!=1)
				{
					ans += "0";
				}
				ans = ans + num[0] + num.substr(2);
			}
			cout << ans << endl;
		}
	}
}
