#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool valid(struct TreeNode* node, long long l, long long r)
{
    if (node == NULL)
    {
        return true;
    }
    if (node->val <= l || node->val >= r)
    {
        return false;
    }
    return valid(node->left, l, node->val) && valid(node->right, node->val, r);
}

bool isValidBST(struct TreeNode* root)
{
    return valid(root, LLONG_MIN, LLONG_MAX);
}
