#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cnt;

void dfs(struct TreeNode* node,int cur)
{
    if(node->val>=cur)
    {
        cur=node->val;
        cnt++;
    }
    if(node->left)
    {
        dfs(node->left,cur);
    }
    if(node->right)
    {
        dfs(node->right,cur);
    }
}

int goodNodes(struct TreeNode* root)
{
    cnt=0;
    if(root)
    {
        dfs(root,INT_MIN);
    }
    return cnt;
}
