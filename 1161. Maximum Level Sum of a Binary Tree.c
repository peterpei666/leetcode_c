#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int depth;
int num[100000];

void dfs(struct TreeNode* node, int d)
{
    if (node)
    {
        depth = max(depth, d);
        num[d] += node->val;
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
}

int maxLevelSum(struct TreeNode* root)
{
    memset(num, 0, sizeof(num));
    depth = 0;
    dfs(root, 0);
    int ans = 0;
    for (int i = 1; i <= depth; i++)
    {
        if (num[i] > num[ans])
        {
            ans = i;
        }
    }
    return ans + 1;
}
