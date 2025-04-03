#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void maxdif(struct TreeNode* node,int min,int max,int* dif)
{
    int temp;
    if(node->val<min)
    {
        min=node->val;
    }
    if(node->val>max)
    {
        max=node->val;
    }
    if(node->left)
    {
        maxdif(node->left,min,max,dif);
    }
    if(node->right)
    {
        maxdif(node->right,min,max,dif);
    }
    if(node->left==NULL&&node->right==NULL)
    {
        if(max-min>*dif)
        {
            *dif=max-min;
        }
    }
}

int maxAncestorDiff(struct TreeNode* root)
{
    int dif=0;
    maxdif(root,root->val,root->val,&dif);
    return dif;
}

