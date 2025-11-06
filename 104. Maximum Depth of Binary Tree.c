#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int depth(struct TreeNode* node, int cur)
{
    if (node == NULL)
    {
        return cur;
    }
    return max(depth(node->left, cur + 1), depth(node->right, cur + 1));
}

int maxDepth(struct TreeNode* root)
{
    return depth(root, 0);
}
