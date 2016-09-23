#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
struct tnode
{
	int data;
	tnode *left;
	tnode *right;
	int height;
};
int max(int a, int b)
{
	return a > b ? a : b;
}
int getHeight(tnode *r)
{
	if (!r)
		return -1;
	else
		return r->height;
}
tnode *LL(tnode *a)
{
	tnode *b = a->left;
	a->left = b->right;
	b->right = a;
	a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
	b->height = max(getHeight(b->left), a->height) + 1;

	return b;
}
tnode *RR(tnode *a)
{
	tnode *b = a->right;
	a->right = b->left;
	b->left = a;
	a->height = max(getHeight(a->left), getHeight(a->right)) + 1;
	b->height = max(getHeight(b->right), a->height) + 1;
	return b;
}
tnode *LR(tnode *a)
{
	a->left = RR(a->left);
	return LL(a);
}

tnode *RL(tnode *a)
{
	a->right = LL(a->right);
	return RR(a);
}
tnode *Insert(tnode *t,int x)
{
	if (!t)
	{
		t = (tnode *)malloc(sizeof(struct tnode));
		t->data = x;
		t->left = t->right = NULL;
		t->height = 0;
	}
	else if (x < t->data)
	{
		t->left = Insert(t->left, x);
		if (getHeight(t->left) - getHeight(t->right) == 2)
		{//左边的树高比右边的高,需要左旋
			if (x < t->left->data)
			{//左单旋
				t = LL(t);
			}
			else
			{//左右双旋
				t = LR(t);
			}
		}
	}
	else if (x > t->data)
	{
		t->right = Insert(t->right, x);
		if (getHeight(t->right) - getHeight(t->left) == 2)
		{//右边的树高比左边的高，需要右旋
			if (x>t->right->data)
			{
				t = RR(t);
			}
			else
			{
				t = RL(t);
			}
		}

	}
	t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
	return t;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		tnode *root = NULL;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			root = Insert(root, x);
		}
		printf("%d\n", root->data);
	}
	return 0;
}
