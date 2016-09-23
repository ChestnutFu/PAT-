#include<stdio.h>
using namespace std;
int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		long long A, B, C;
		for (int i = 1; i <= t;i++)
		{
			scanf("%lld%lld%lld", &A, &B, &C);
			bool flag;
			long long ans = A + B;
			if (A > 0 && B > 0&&ans<=0)
				flag = true;
			else if (A < 0 && B < 0&&ans>=0)
				flag = false;
			else
				flag = (ans > C);
			printf("Case #%d: ", i);
			if (flag)
				printf("true\n");
			else
				printf("false\n");
		}
	}
	return 0;
}
