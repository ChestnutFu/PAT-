#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
struct node
{
	string name;
	string password;
};
bool modified(node &a)
{
	bool flag = false;
	int len = a.password.length();
	for (int i = 0; i < len; i++)
	{
		char c = a.password[i];
		switch (c)
		{
		case '1':
			a.password[i] = '@';
			flag = true;
			break;
		case '0':
			a.password[i] = '%';
			flag = true;
			break;
		case 'l':
			a.password[i] = 'L';
			flag = true;
			break;
		case 'O':
			a.password[i] = 'o';
			flag = true;
			break;
		default:
			break;
		}
	}
	return flag;
}
int main()
{
	int n;
	vector<node>user;
	while (scanf("%d", &n) != EOF)
	{
		user.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> user[i].name >> user[i].password;
		}
		if (n < 1)
		{
			printf("There is %d account and no account is modified\n",n);
			continue;
		}
		int s = 0;
		vector<node>list;
		for (int i = 0; i < n; i++)
		{
			if (modified(user[i]))
			{
				list.push_back(user[i]);
				s++;
			}
		}
		if (s == 0)
			if (n == 1)
				printf("There is %d account and no account is modified\n", n);
			else
				printf("There are %d accounts and no account is modified\n", n);
		else
		{
			printf("%d\n", s);
			for (int i = 0; i < s; i++)
			{
				cout << list[i].name << " " << list[i].password << endl;
			}
		}
	}
	return 0;
}
