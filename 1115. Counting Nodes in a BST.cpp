#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
	int level;
	int val;
	node *left;
	node *right;
};
node *Insert(node *root,int x)
{
	if (root == NULL)
	{
		root = (node *)malloc(sizeof(struct node));
		root->left = root->right = NULL;
		root->val = x;
	}
	else
	{
		if (x <= root->val)
			root->left = Insert(root->left, x);
		else
			root->right = Insert(root->right, x);
	}
	return root;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		node *root = NULL;
		while (n--)
		{
			int tmp;
			scanf("%d", &tmp);
			root = Insert(root, tmp);
		}
		int level, maxlevel = 0, num1 = 0, num2;
		queue<node*>q;
		q.push(root);
		root->level = 1;
		while (!q.empty())
		{
			node *a = q.front();
			q.pop();
			if (a->level > maxlevel)
			{
				maxlevel = a->level;
				num2 = num1;
				num1 = 1;
			}
			else if (a->level == maxlevel)
			{
				num1++;
			}

			if (a->left != NULL)
			{
				a->left->level = a->level + 1;
				q.push(a->left);
			}
			if (a->right != NULL)
			{
				a->right->level = a->level + 1;
				q.push(a->right);
				
			}
		}
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	}
	return 0;
}
