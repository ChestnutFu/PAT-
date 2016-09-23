#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<set>
#include<functional>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		stack<int>s;
		multiset<int>min, max;
		multiset<int>::iterator it;
		int mid = -1;
		while (n--)
		{
			char str[11];
			scanf("%s", &str);
			if (str[1] == 'o')
			{//输入的数Pop
				if (s.empty())
					printf("Invalid\n");
				else
				{
					int x = s.top();
					s.pop();
					printf("%d\n", x);
					if (mid >= x)
					{
						it = min.find(x);
						min.erase(it);
					}
					else
					{
						it = max.find(x);
						max.erase(it);
					}

					if (max.size() + 1 < min.size())
					{
						it = min.end();
						--it;
						max.insert(*it);
						min.erase(it);
					}
					else if (max.size() > min.size())
					{
						it = max.begin();
						min.insert(*it);
						max.erase(it);
					}
					if (s.size() > 0)
					{
						it = min.end();
						it--;
						mid = *it;
					}
				}
			}
			else if (str[1] == 'u')
			{//输入的是Push
				int x;
				scanf("%d", &x);
				if (s.size() == 0)
				{
					min.insert(x);
					mid = x;
				}
				else if (x > mid)
					max.insert(x);
				else
					min.insert(x);
				s.push(x);

				if (max.size() + 1 < min.size())
				{
					it = min.end();
					it--;
					max.insert(*it);
					min.erase(it);
				}
				else if (max.size() > min.size())
				{
					it = max.begin();
					min.insert(*it);
					max.erase(it);
				}
				if (s.size() != 0)
				{
					it = min.end();
					it--;
					mid = *it;
				}
			}
			else if (str[1]=='e')
			{//输入的是PeekMedian
				if (s.empty())
					printf("Invalid\n");
				else
					printf("%d\n", mid);
			}
			else
			{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}
