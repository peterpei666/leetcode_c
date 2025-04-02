#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void count(struct TreeNode* node,int* num)
{
	if(node==NULL)
	{
		return;
	}
	(*num)++;
	if(node->left)
	{
		count(node->left,num);
	}
	if(node->right)
	{
		count(node->right,num);
	}
}

int countNodes(struct TreeNode* root)
{
	int num=0;
	count(root,&num);
	return num;
}
