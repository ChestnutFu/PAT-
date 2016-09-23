#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct node
{
	int *data;
	int top;
	int capacity;
};
typedef struct node * Stack;
Stack creat(int n)
{
	Stack s;
	s = (Stack)malloc(sizeof(struct node));
	s->data = (int *)malloc(sizeof(int)*n);
	s->top = -1;
	s->capacity = n;

	return s;
}
bool IsEmpty(Stack s)
{
	return s->top == -1;
}
bool IsFull(Stack s)
{
	return s->capacity - 1 == s->top;
}
bool push(Stack s, int x)
{
	if (IsFull(s))
	{
		return false;
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return true;
	}
}
int pop(Stack s)
{
	if (IsEmpty(s))
		return -1;
	else
	{
		int x = s->data[s->top];
		s->top--;
		return x;
	}
}
int main()
{
	int m, n, k;
	while (scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		while (k--)
		{
			bool flag = true;
			Stack s = creat(m);
			vector<int>l(n);
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &l[i]);
			}
			int index = 0;
			int x = 1;
			while (1)
			{
				if (push(s,x) == false)
				{//如果栈已经满了
					flag = false;
					break;
				}
				else
				{//把x入栈后比较x和index是否相等
					int v = s->data[s->top];
					while (v==l[index])
					{
						pop(s);
						index++;
						if (IsEmpty(s))
							break;
						v = s->data[s->top];
					}
				}
				x++;
				if (index == n || x == n + 1)
					break;
			}
			if (index != n || x != n + 1)
				flag = false;
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
