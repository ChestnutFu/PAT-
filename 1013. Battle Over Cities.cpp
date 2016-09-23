#include<iostream>
#include<stdio.h>
#define Max 99999
using namespace std;
struct w{
	int x;
	int y;
};
typedef struct w *W;
int findroot(int map[],int x)
{
	int root;
	if (map[x] < 0)
		root = x;
	else
		root = map[x];
	return root;
}
int min(int a, int b,int map[])
{
	return map[a]>map[b] ? b : a;
}
int max(int a, int b,int map[])
{
	return map[a] > map[b] ? a : b;
}
void Insert(int map[], int c1, int c2,int N)
{
	int r1, r2;
	r1 = findroot(map, c1);
	r2 = findroot(map, c2);
	if (r1 != r2)
	{
		int R = min(r1, r2, map);
		int change = max(r1, r2, map);
		map[R] = map[change] + map[R];
		map[change] = R;
	}
}
int main()
{
	int N, M, K;
	while (scanf("%d%d%d", &N, &M, &K) != EOF)
	{
		//N:total number of cities
		//M:remaining highways
		//K:the number of cities to be checked
		int i, j;
		int map[1001];
		int c1, c2;
		W way = (W)malloc(sizeof(struct w)*M);
		for (i = 0; i < M; i++)
		{
			scanf("%d%d", &c1, &c2);
			way[i].x = c1;
			way[i].y = c2;
		}
		while (K--)
		{
			int c;
			scanf("%d", &c);
			for (i = 1; i <= N; i++)
			{
				map[i] = -1;
			}
			for (i = 0; i < M; i++)
			{
				if (way[i].x != c&&way[i].y != c)
					Insert(map, way[i].x, way[i].y, N);
			}
			int highway = 0;
			for (i = 1; i <= N; i++)
			{
				if (map[i] < 0)
					highway++;
			}
			highway -= 2;
			printf("%d\n", highway);
		}
	}
	return 0;
}
