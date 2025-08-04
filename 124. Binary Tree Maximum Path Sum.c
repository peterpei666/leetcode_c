#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(struct TreeNode* node,int* ans)
{
    if(node==NULL)
    {
        return 0;
    }
    int l=dfs(node->left,ans);
    int r=dfs(node->right,ans);
    *ans=max(*ans,node->val+max(0,l)+max(0,r));
    return max(0,node->val+max(0,max(l,r)));
}

int maxPathSum(struct TreeNode* root)
{
    int ans=INT_MIN;
    dfs(root,&ans);
    return ans;
}
