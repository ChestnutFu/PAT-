#include<iostream>  
#include<vector>  
#include<algorithm>  
typedef struct Node
{
	double sum;
	int e;
}Node;
#define MAX 3000  
int main()
{
	int n1, n2;
	while (scanf("%d", &n1) != EOF)
	{
		std::vector<Node> a(n1);
		for (int i = 0; i < n1; ++i)
			scanf("%d %lf\n", &a[i].e, &a[i].sum);
		scanf("%d", &n2);
		std::vector<Node> b(n2);
		for (int i = 0; i < n2; ++i)
			scanf("%d %lf", &b[i].e, &b[i].sum);
		//product  
		std::vector<double> p;
		p.assign(MAX + 1, 0.0);
		for (int i = 0; i < n1; ++i)
		{
			for (int j = 0; j < n2; ++j)
			{
				Node tmp;
				tmp.e = a[i].e + b[j].e;
				tmp.sum = a[i].sum*b[j].sum;
				p[tmp.e] += tmp.sum;
			}
		}
		//output  
		int cnt = 0;
		for (int i = MAX; i >= 0; --i)
		{
			if (std::fabs(p[i]) > 1e-6)
				cnt++;
		}
		printf("%d", cnt);
		for (int i = MAX; i >= 0; --i)
		{
			if (std::fabs(p[i]) > 1e-6)
				printf(" %d %.1lf", i, p[i]);
		}
		printf("\n");
	}
	return 0;
}

