#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int mp[6001];
int n, idx;

static inline struct TreeNode* create(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int* postorder, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    struct TreeNode* root = create(postorder[idx]);
    idx--;
    root->right = build(postorder, mp[root->val + 3000] + 1, r);
    root->left = build(postorder, l, mp[root->val + 3000] - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    n = inorderSize;
    idx = n - 1;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i] + 3000] = i;
    }
    return build(postorder, 0, n - 1);
}
