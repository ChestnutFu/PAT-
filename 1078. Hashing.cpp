#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
bool IsPrime(int x)
{
	if (x == 1)
		return false;
	if (x == 2 || x == 3)
		return true;
	else
	{
		for (int i = 2; i*i <= x; i++)
		{
			if (x%i == 0)
				return false;
		}
		return true;
	}

}
int main()
{
	int mSize, n;
	while (scanf("%d%d",&mSize,&n)!=EOF)
	{
		while (!IsPrime(mSize))
		{
			mSize++;
		}
		vector<int>Table(mSize, -1);

		while (n--)
		{
			int num;
			scanf("%d", &num);
			int i;
			for (i = 0; i < mSize; i++)
			{
				if (Table[(num+i*i)%mSize] == -1)
				{
					printf("%d", (num + i*i) % mSize);
					Table[(num + i*i) % mSize] = 1;
					break;
				}
			}
			if (i == mSize)
				printf("-");
			printf("%c", n ? ' ' : '\n');
		}
	}
}
