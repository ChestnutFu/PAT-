#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string a[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string b[] = { "", "Shi", "Bai", "Qian" };
string c[] = { "", "Wan", "Yi" };
string s;
int main()
{
	while (cin>>s)
	{
		int read = 0, len = s.length();
		if (s[read] == '-')
		{
			printf("Fu ");
			read++;
		}
		len--;
		while (s[read]=='0')
		{
			read++;
		}
		if (read - 1 == len)
			cout << "ling";
		while (read<=len)
		{
			if (s[read] != '0')
			{
				cout << a[s[read] - '0'];
				if ((len - read) % 4 == 0 && (len - read) / 4 > 0)
					cout << " " << c[(len - read) / 4];
				if ((len - read) % 4 != 0)
				{
					cout << " " << b[(len - read) % 4];
				}
				if (read != len)
				{
					bool f = false;
					for (int i = read + 1; i <= len; i++)
					{
						if (s[i] != '0')
							f = true;
					}
					if (f)
						cout << " ";
					else
					{
						if ((len - read) / 4 > 0)
							cout << " " << c[(len - read) / 4];
						break;
					}
				}
			}
			else
			{
				int time;
				time = (len - read) % 4;
				bool flag = false;
				int i;
				for (i = read; i <= read + time; i++)
				{
					if (s[i] != '0')
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					cout << "ling ";
					read = i - 1;
				}
				else
				{
					if ((len - read) % 4 == 0 && (len - read) / 4 > 0)
					{
						cout << c[(len - read) / 4] << " ";
					}
				}
			}
			read++;
		}
	}
}
