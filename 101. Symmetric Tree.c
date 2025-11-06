#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root)
{
    return check(root, root);
}
