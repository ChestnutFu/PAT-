#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int a, b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		int sum = a + b;
		string s;

		//如果是负数
		if (sum < 0)
		{
			printf("-");
			sum *= -1;
		}
		int cur = 0;
		do
		{
			int r = sum % 10;
			sum /= 10;
			if (cur < 3)
			{
				s.insert(s.begin(), r + '0');
				cur++;
			}
			else
			{
				s.insert(s.begin(), ',');
				s.insert(s.begin(), r + '0');
				cur = 1;
			}

		} while (sum > 0);
		cout << s << endl;
	}
}
