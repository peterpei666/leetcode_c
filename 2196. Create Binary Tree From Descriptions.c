#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createBinaryTree(int** descriptions, int n, int* descriptionsColSize)
{
    struct TreeNode* node[100002] = {0};
    bool child[100002] = {0};
    for (int i = 0; i < n; i++)
    {
        if (node[descriptions[i][0]] == NULL)
        {
            struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            temp->val = descriptions[i][0];
            temp->left = NULL;
            temp->right = NULL;
            node[descriptions[i][0]] = temp;
        }
        if (node[descriptions[i][1]] == NULL)
        {
            struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            temp->val = descriptions[i][1];
            temp->left = NULL;
            temp->right = NULL;
            node[descriptions[i][1]] = temp;
        }
        child[descriptions[i][1]] = true;
        if (descriptions[i][2])
        {
            node[descriptions[i][0]]->left = node[descriptions[i][1]];
        }
        else
        {
            node[descriptions[i][0]]->right = node[descriptions[i][1]];
        }
    }
    for (int i = 0; i <= 100000; i++)
    {
        if (node[i] && !child[i])
        {
            return node[i];
        }
    }
    return NULL;
}
