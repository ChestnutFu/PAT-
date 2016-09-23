#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int m, n, l, t;
int map[1286][128][60];
int ans = 0;
int nx[] = { 1, -1, 0, 0, 0, 0 };
int ny[] = { 0, 0, 1, -1, 0, 0 };
int nz[] = { 0, 0, 0, 0, 1, -1 };
struct node
{
	int x; int y; int z;
	node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};
bool InRange(int x,int y,int z)
{
	return x < m&&x >= 0 && y < n&&y >= 0 && z < l&&z >= 0;
}
void bfs(int x, int y, int z)
{
	queue<node>q;
	int res = 0;
	q.push(node(x, y, z));
	map[x][y][z] = 0;
	res++;
	while (!q.empty())
	{
		node d = q.front();
		q.pop();
		int dx = d.x;
		int dy = d.y;
		int dz = d.z;
		for (int i = 0; i < 6; i++)
		{
			int tx = dx + nx[i];
			int ty = dy + ny[i];
			int tz = dz + nz[i];
			if (InRange(tx, ty, tz) && map[tx][ty][tz] == 1)
			{
				q.push(node(tx, ty, tz));
				map[tx][ty][tz] = 0;
				res++;
			}
		}
	}
	if (res >= t)
		ans += res;
}

int main()
{
	while (scanf("%d%d%d%d",&m,&n,&l,&t)!=EOF)
	{
		int i, j, k;
		for (i = 0; i < l; i++)
			for (j = 0; j < m; j++)
				for (k = 0; k < n; k++)
					scanf("%d", &map[j][k][i]);
		for (i = 0; i < l; i++)
			for (j = 0; j < m; j++)
				for (k = 0; k < n; k++)
					if (map[j][k][i] == 1)
						bfs(j, k, i);
		printf("%d\n", ans);
	}
	return 0;
}
