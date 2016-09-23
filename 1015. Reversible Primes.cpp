#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int rever_num(int N,int D)
{
	int sum = 0, num, m = 1;
	while (N!=0)
	{
		num = N%D;
		N /= D;
		sum *= D;
		sum += num;
	}
	return sum;
}
bool IsPrime(int num)
{
	if (num == 1)
		return false;
	if (num == 2||num==3)
		return true;
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int N, D;
	while (scanf("%d", &N) != EOF&&N > 0)
	{
		scanf("%d", &D);
		int num = rever_num(N, D);
		if (IsPrime(num) && IsPrime(N))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
