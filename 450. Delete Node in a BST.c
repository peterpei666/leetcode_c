#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        struct TreeNode* temp = root->left;
        while (temp->right)
        {
            temp = temp->right;
        }
        root->val = temp->val;
        root->left = deleteNode(root->left, temp->val);
    }
    return root;
}
