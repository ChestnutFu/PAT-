#include<iostream>
#include<string>
using namespace std;
bool IsPalindromic(string s)
{
	int len = s.length();
	int i;
	for (i = 0; i <= len / 2 + 1; i++)
	{
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}
int char2int(char a)
{
	return a - '0';
}
char int2char(int a)
{
	return a + '0';
}
void newstring(string s,string &nstr)
{
	nstr.clear();
	int len = s.length();
	int carry = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		int now = (char2int(s[i]) + char2int(s[len - 1 - i])) + carry;
		nstr.insert(nstr.begin(), int2char(now % 10));
		carry = now / 10;
	}
	if (carry != 0)
		nstr.insert(nstr.begin(), int2char(carry));
}
int main()
{
	string N;
	int step;
	while (cin >> N >> step)
	{
		int S = 0;
		string str = N;
		string s;
		while (S < step)
		{
			if (IsPalindromic(str))
				break;
			newstring(str, s);
			str = s;
			S++;
		}
		cout << str << endl << S << endl;
	}
}
