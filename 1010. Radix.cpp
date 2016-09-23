#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long int getValue(long long int Radix,char *s)
{
	long long int sum = 0, num, m = 1;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] >= '0'&&s[i] <= '0')
			num = s[i] - '0';
		else
			num = s[i] - 'a' + 10;
		num *= m;
		sum += num;
		m *= Radix;
	}
	return sum;
}
long long int maxx(char *s)
{
	int len = strlen(s);
	int max = -1, num;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
			num = s[i] - '0';
		else
			num = s[i] - 'a' + 10;
		if (num > max)
			max = num;
	}
	return max + 1;

}
long long int max(long long int a,long long int b)
{
	return a > b ? a : b;
}
int cmp(long long int target,char *s,long long int redix)
{
	long long int sum = 0, num, m = 1;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
			num = s[i] - '0';
		else
			num = s[i] - 'a' + 10;
		num *= m;
		m *= redix;
		sum += num;
		if (sum > target)
			return 1;
	}
	if (sum == target)
		return 0;
	if (sum < target)
		return -1;
}
long long int BinarySearch(char *s,long long int target)
{
	long long int L = maxx(s);
	long long int R = max(L, target), M;

	while (R >= L)
	{
		M = (R + L) / 2;
		int x = cmp(target, s, M);
		if (x == 0)
			return M;
		else if (x == -1)
			L = M + 1;
		else
			R = M - 1;
	}
	return -1;
}
int main()
{
	char a[11], b[11];
	int tag;
	long long int Radix;
	long long int target, search;
	while (scanf("%s%s%d%lld",&a,&b,&tag,&Radix)!=EOF)
	{
		if (strcmp(a, "1") == 0 && strcmp(b, "1") == 0)
		{
			printf("2\n");
			continue;
		}
		if (a == b)
		{
			printf("%lld\n", Radix);
			continue;
		}
		if (tag == 1)
		{
			target = getValue(Radix, a);
			search = BinarySearch(b, target);
		}
		else
		{
			target = getValue(Radix, a);
			search = BinarySearch(a, target);
		}
		if (search == -1)
			printf("Impossible\n");
		else
			printf("%lld\n", search);
	}
	return 0;
}
