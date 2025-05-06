#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkTree(struct TreeNode* root)
{
    return root->val==root->left->val+root->right->val;
}
