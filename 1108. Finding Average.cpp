#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	int n;
	vector<double>nums;
	while (scanf("%d",&n)!=EOF)
	{
		nums.clear();
		string s;
		while (n--)
		{
			bool flag = true;
			cin >> s;
			int marksTime = 0, mark = -1;
			string str = "";
			for (int i = 0; i < s.length(); i++)
			{
				if (i == 0)
				{
					if (s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))
						str.insert(str.end(), s[i]);
					else if (s[i] != '+')
					{
						cout << "ERROR: " << s << " is not a legal number" << endl;
						flag = false;
						break;
					}
				}
				else
				{
					if (s[i] >= '0'&&s[i] <= '9')
						str.insert(str.end(), s[i]);
					else if (s[i] == '.'&&marksTime == 0)
					{
						marksTime++;
						str.insert(str.end(), s[i]);
						mark = i;
					}
					else
					{
						cout << "ERROR: " << s << " is not a legal number" << endl;
						flag = false;
						break;
					}
				}
			}
			if (mark != -1 && str.length() -1 - mark > 2)
			{
				cout << "ERROR: " << s << " is not a legal number" << endl;
				continue;
			}

			if (flag)
			{
				double x;
				stringstream ss;
				ss << str;
				ss >> x;
				if (x > 1000.0 || x < -1000.0)
				{
					cout << "ERROR: " << s << " is not a legal number" << endl;
					continue;
				}
				nums.push_back(x);
			}
		}
		if (nums.size() == 0)
			printf("The average of 0 numbers is Undefined\n");
		else if (nums.size() == 1)
			printf("The average of 1 number is %.2lf\n", nums[0]);
		else
		{
			double avg = 0.0;
			for (int i = 0; i < nums.size(); i++)
			{
				avg += nums[i];
			}
			avg /= (double)nums.size();
			printf("The average of %d numbers is %.2lf\n", nums.size(), avg);
		}
	}
	return 0;
}
