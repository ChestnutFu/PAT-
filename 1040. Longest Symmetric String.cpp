#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<string.h>  
#include<vector>  

#define Max 10000  
int dp[2 * Max + 1];
char str[Max];

int mmax(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	while (gets(str))
	{
		//memset(dp, -1, sizeof(dp));  
		int len = strlen(str);
		//insert special character into str, must not appeared in str  
		std::vector<int> magic;
		for (int i = 0; i < len; ++i)
		{
			magic.push_back(-1);//special character  
			magic.push_back(str[i]);//character to int  
		}
		magic.push_back(-1);
		//enumerate center point for magic vector  
		len = (int)magic.size();
		int max = 1;
		for (int i = 1; i < len; ++i)
		{
			int l, r;
			int step = 1;
			for (l = i - 1, r = i + 1; l >= 0 && r < len; l--, r++)
			{
				if (magic[l] != magic[r])
					break;
				step += 2;
			}
			max = mmax(max, step);
		}

		printf("%d\n", max / 2);
	}
	return 0;
}
