#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string a[] = { "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string b[] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		getchar();
		while (n--)
		{
			string s;
			getline(cin, s);
			if (s[0] >= '0'&&s[0] <= '9')
			{
				int i;
				int num = 0;
				int k = 1;
				for (i = s.length() - 1; i >= 0; i--)
				{
					num += (s[i] - '0')*k;
					k *= 10;
				}
				int D = num / 13;
				int d = num % 13;
				if (D == 0 && d == 0)
					cout << "tret";
				if (D != 0)
					cout << b[D - 1];
				if (D != 0 && d != 0)
					cout << " ";
				if (d != 0)
					cout << a[d - 1];
				cout << endl;
			}
			else
			{
				if (s.length() == 3)
				{
					int i;
					for (i = 0; i < 12; i++)
					{
						if (s == a[i])
							break;
					}
					if (i == 12)
					{
						for (i = 0; i < 12; i++)
						{
							if (s == b[i])
								break;
						}
						cout << 13 * (i + 1) << endl;
					}
					else
						cout << i + 1 << endl;
				}
				else if (s == "tret")
				{
					cout << "0" << endl;
				}
				else
				{
					int i;
					int num = 0;
					string x = s.substr(0, 3);
					for (i = 0; i < 12; i++)
					{
						if (x == b[i])
							break;
					}
					num += 13 * (i + 1);
					x = s.substr(4);
					for (i = 0; i < 12; i++)
					{
						if (x == a[i])
							break;
					}
					num += (i + 1);
					cout << num << endl;
				}
			}
		}
	}
	return 0;
}
