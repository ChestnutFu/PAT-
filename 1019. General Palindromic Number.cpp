#include<iostream>
#include<vector>
void GetReverseNumberBaseD(int N, int D,std::vector<int>& a)
{
	do
	{
		int temp = N%D;
		a.push_back(temp);
		N /= D;
	} while (N != 0);
}
bool Ispalindromic(const std::vector<int>&x)
{
	int n = (int)x.size();
	for (int i = 0; i < n; i++)
	{
		if (x[i] != x[n - 1 - i])
			return false;
	}
	return true;
}
int main()
{
	int N, d;
	while (scanf("%d%d",&N,&d)!=EOF)
	{
		std::vector<int>x;
		GetReverseNumberBaseD(N, d, x);

		if (Ispalindromic(x))
			printf("Yes\n");
		else
			printf("No\n");

		int n = (int)x.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (i == 0)
				printf("%d\n", x[i]);
			else
				printf("%d ", x[i]);
		}
	}
	return 0;
}
