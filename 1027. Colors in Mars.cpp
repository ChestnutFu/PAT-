#include<iostream>
#include<vector>
using namespace std;
char CharTable[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
int main()
{
	int red, green, blue;
	vector<int>color;
	while (cin >> red >> green >> blue)
	{
		color.assign(6, 0);
		color[0] = red / 13;
		color[1] = red % 13;
		color[2] = green / 13;
		color[3] = green % 13;
		color[4] = blue / 13;
		color[5] = blue % 13;

		cout << "#";
		for (int i = 0; i < 6; i++)
		{
			cout << CharTable[color[i]];
		}
	}
	return 0;
}
