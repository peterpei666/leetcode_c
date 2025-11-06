#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* p1;
struct TreeNode* p2;
struct TreeNode* prev;

void find(struct TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }
    find(node->left);
    if (prev && node->val < prev->val)
    {
        if (p1 == NULL)
        {
            p1 = prev;
        }
        p2 = node;
    }
    prev = node;
    find(node->right);
}

void recoverTree(struct TreeNode* root)
{
    p1 = NULL;
    p2 = NULL;
    prev = NULL;
    find(root);
    int temp = p1->val;
    p1->val = p2->val;
    p2->val = temp;
}
