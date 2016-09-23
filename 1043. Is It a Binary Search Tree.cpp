#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<int>list;
vector<int>pre;
vector<int>post;
struct node
{
	int val;
	node *left;
	node *right;
};
node *leftInsert(int x,node *root)
{
	
	if (root)
	{
		if (x < root->val)
			root->left=leftInsert(x, root->left);
		else
			root->right=leftInsert(x, root->right);
	}
	else
	{
		root = (node*)malloc(sizeof(struct node));
		root->val = x;
		root->left = root->right = NULL;
	}
	return root;
}
node *rightInsert(int x, node *root)
{

	if (root)
	{
		if (x >= root->val)
			root->left=rightInsert(x, root->left);
		else
			root->right=rightInsert(x, root->right);
	}
	else
	{
		root = (node*)malloc(sizeof(struct node));
		root->val = x;
		root->left = root->right = NULL;
	}
	return root;
}
void treePre(node *root)
{
	if (root != NULL)
	{
		pre.push_back(root->val);
		treePre(root->left);
		treePre(root->right);
	}
}
void treePost(node *root)
{
	if (root != NULL)
	{
		treePost(root->left);
		treePost(root->right);
		post.push_back(root->val);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		list.clear();
		list.resize(n);
		node *leftRoot = NULL, *rightRoot = NULL;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &list[i]);
			leftRoot = leftInsert(list[i],leftRoot);
			rightRoot = rightInsert(list[i], rightRoot);
		}
		pre.clear();
		treePre(leftRoot);
		if (pre == list)
		{
			printf("YES\n");
			post.clear();
			treePost(leftRoot);
			for (int i = 0; i < post.size(); i++)
			{
				printf("%d", post[i]);
				if (i == post.size() - 1)
					printf("\n");
				else
					printf(" ");
			}
		}
		else
		{
			pre.clear();
			treePre(rightRoot);
			if (pre == list)
			{
				printf("YES\n");
				post.clear();
				treePost(rightRoot);
				for (int i = 0; i < post.size(); i++)
				{
					printf("%d", post[i]);
					if (i == post.size() - 1)
						printf("\n");
					else
						printf(" ");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
