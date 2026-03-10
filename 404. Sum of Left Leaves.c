#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(int* ans, struct TreeNode* node, bool isLeft)
{
    if (node == NULL)
    {
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        if (isLeft)
        {
            (*ans) += node->val;
        }
        return;
    }
    dfs(ans, node->left, true);
    dfs(ans, node->right, false);
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    int ans = 0;
    dfs(&ans, root, false);
    return ans;
}
