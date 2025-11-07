#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* node, int cur, int* ans)
{
    if (!node ->left && !node->right)
    {
        (*ans) += cur * 10 + node->val;
        return;
    }
    if (node->left)
    {
        dfs(node->left, cur * 10 + node->val, ans);
    }
    if (node->right)
    {
        dfs(node->right, cur * 10 + node->val, ans);
    }
};

int sumNumbers(struct TreeNode* root)
{
    int ans = 0;
    dfs(root, 0, &ans);
    return ans;
}
