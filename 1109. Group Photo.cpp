#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	int hight;
};
bool cmp(node a,node b)
{
	if (a.hight == b.hight)
		return a.name < b.name;
	else
		return a.hight > b.hight;
}
int main()
{
	int n, k;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		int i;
		int numInRow = n / k;
		int numLastRow = n - numInRow*(k - 1);
		vector<vector<string>>photo(k);
		for (i = 0; i < k; i++)
		{
			if (i == 0)
				photo[i].resize(numLastRow);
			else
				photo[i].resize(numInRow);
		}
		vector<node>person(n);
		for (i = 0; i < n; i++)
		{
			cin >> person[i].name >> person[i].hight;
		}
		sort(person.begin(), person.end(), cmp);

		/*插入*/
		//最后一行
		int time = 0;//次数
		int pos = 1;
		int stand = numLastRow / 2;
		vector<bool>flag(numLastRow, false);
		for (i = 0; i < numLastRow; i++)
		{
			photo[0][stand] = person[i].name;
			flag[stand] = true;

			time++;
			int s = stand;
			if (time % 2)
			{
				stand = numLastRow / 2 + pos*-1;
				if (stand < 0||flag[stand]==true)
				{
					stand = s + 1;
				}
			}
			else
			{
				stand = numLastRow / 2 + pos;
				pos++;
				if (stand >= numLastRow || flag[stand] == true)
				{
					stand = s - 1;
				}
			}
		}
		for (i = 0; i < numLastRow; i++)
		{
			cout << photo[0][i];
			if (i != numLastRow - 1)
				printf(" ");
		}
		cout << endl;
		//其他行
		int j;
		int star = numLastRow;
		int end;
		for (j = 1; j < k; j++)
		{
			end = star + numInRow;
			time = 0;
			pos = 1;
			stand = numInRow / 2;
			flag.clear();
			flag.resize(numInRow);
			for (i = star; i < end; i++)
			{
				photo[j][stand] = person[i].name;
				flag[stand] = true;

				time++;
				int s = stand;
				if (time % 2)
				{
					stand = numInRow / 2 + pos*-1;
					if (stand < 0 || flag[stand] == true)
					{
						stand = s + 1;
					}
				}
				else
				{
					stand = numInRow / 2 + pos;
					pos++;
					if (stand >= numInRow || flag[stand] == true)
					{
						stand = s - 1;
					}
				}
			}
			star = end;
		}
		for (j = 1; j < k; j++)
		{
			for (i = 0; i < numInRow; i++)
			{
				cout << photo[j][i];
				if (i != numInRow - 1)
					printf(" ");
			}
			cout << endl;
		}
	}
}
