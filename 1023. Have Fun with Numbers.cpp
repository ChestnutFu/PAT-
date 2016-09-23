#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

void GetCntTable(string a,vector<int>&cntTable)
{
	cntTable.assign(10, 0);
	for (int i = 0; i < a.size(); i++)
	{
		cntTable[a[i] - '0']++;
	}
}
char Int2char(int a)
{
	return a + '0';
}
int Get2Int(char a)
{
	return a - '0';
}
void GetDouble(string a, string &ans)
{
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		carry += (Get2Int(a[i]) * 2);
		char c = Int2char(carry % 10);
		ans.insert(ans.begin(), c);
		carry /= 10;
	}
	if (carry != 0)
		ans.insert(ans.begin(), Int2char(carry));
}
int main()
{

	string str;
	cin >> str;
	vector<int>cntTable;
	GetCntTable(str,cntTable);
	string ans;
	GetDouble(str, ans);
	vector<int>cntTable2;
	GetCntTable(ans, cntTable2);
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		if (cntTable[i] != cntTable2[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	cout << ans << endl;
	system("pause");
	return 0;
}

