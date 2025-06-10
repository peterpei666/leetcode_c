#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int ans;

int dfs(struct TreeNode* node,int start)
{
    int depth=0;
    if(node==NULL)
    {
        return 0;
    }
    int l=dfs(node->left,start);
    int r=dfs(node->right,start);
    if(node->val==start)
    {
        ans=max(l,r);
        return -1;
    }
    if(l>=0&&r>=0)
    {
        depth=max(l,r)+1;
    }
    else
    {
        int dis=abs(l)+abs(r);
        ans=max(ans,dis);
        depth=min(l,r)-1;
    }
    return depth;
}

int amountOfTime(struct TreeNode* root, int start)
{
    ans=0;
    dfs(root,start);
    return ans;
}
