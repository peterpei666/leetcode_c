#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

inline int max(int a,int b)
{
    return a>b?a:b;
}

int depth(int current,struct TreeNode* node)
{
    if(node==NULL)
    {
        return current;
    }
    else
    {
        int a=depth(current+1,node->left);
        int b=depth(current+1,node->right);
        return max(a,b);
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
{
    int l=depth(0,root->left);
    int r=depth(0,root->right);
    if(l>r)
    {
        return subtreeWithAllDeepest(root->left);
    }
    else if(l<r)
    {
        return subtreeWithAllDeepest(root->right);
    }
    else
    {
        return root;
    }
}
