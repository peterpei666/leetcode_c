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

inline int abs(int a)
{
    return a < 0 ? -a : a;
}

int depth(struct TreeNode* node, int cur)
{
    if (node == NULL)
    {
        return cur;
    }
    return max(depth(node->left, cur + 1), depth(node->right, cur + 1));
}

bool isBalanced(struct TreeNode* root)
{
    if (!root)
    {
        return true;
    }
    return abs(depth(root->left, 0) - depth(root->right, 0)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}
