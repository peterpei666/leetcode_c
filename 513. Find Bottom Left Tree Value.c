#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* node,int cur,int* depth,int* ans)
{
    if(node->left)
    {
        dfs(node->left,cur+1,depth,ans);
    }
    if(cur>*depth)
    {
        *depth=cur;
        *ans=node->val;
    }
    if(node->right)
    {
        dfs(node->right,cur+1,depth,ans);
    }
}

int findBottomLeftValue(struct TreeNode* root)
{
    int depth=0,ans=0;
    dfs(root,1,&depth,&ans);
    return ans;
}
