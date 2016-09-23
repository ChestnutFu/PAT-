/*用快排也可以
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct heapnode
{
	int capcity;
	int size;
	int* h;
};
typedef struct heapnode *Heap;
Heap creat(int n)
{
	Heap H;
	H = (Heap)malloc(sizeof(struct heapnode));
	H->h = (int *)malloc(sizeof(int)*(n + 1));
	H->h[0] = 0;
	H->capcity = n;
	H->size = 0;
	return H;
}
void insert(Heap H,int num)
{
	H->size++;
	int i = H->size;
	
	for (; H->h[i / 2] > num; i /= 2)
	{
		H->h[i] = H->h[i / 2];
	}
	H->h[i] = num;
}
int Delete(Heap H)
{
	int num = H->h[1];

	int parent, child;
	int x = H->h[H->size--];
	for (parent = 1; parent * 2 < H->size; parent = child)
	{
		child = parent * 2;
		if (child + 1 < H->size&&H->h[child] > H->h[child + 1])
			child++;
		if (x <= H->h[child])
			break;
		else
			H->h[parent] = H->h[child];
	}
	H->h[parent] = x;

	return num;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int sum = 0;
		int i;

		int emp;
		Heap H = creat(n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &emp);
			sum += emp;
			insert(H, emp);
		}
		int minsum = 0;
		for (i = 0; i < n / 2; i++)
		{
			emp = Delete(H);
			minsum += emp;
		}
		if (n % 2 == 1)
			printf("1 ");
		else
			printf("0 ");
		printf("%d", sum - minsum * 2);
	}
	return 0;
}
