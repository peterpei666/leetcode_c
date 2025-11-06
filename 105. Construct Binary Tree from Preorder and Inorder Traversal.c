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

struct TreeNode* build(int* preorder, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    struct TreeNode* root = create(preorder[idx]);
    idx++;
    root->left = build(preorder, l, mp[root->val + 3000] - 1);
    root->right = build(preorder, mp[root->val + 3000] + 1, r);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    n = preorderSize;
    idx = 0;
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i] + 3000] = i;
    }
    return build(preorder, 0, n - 1);
}
