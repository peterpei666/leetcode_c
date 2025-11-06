#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline struct TreeNode* create(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int nums[], int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int mid = (l + r) / 2;
    struct TreeNode* node = create(nums[mid]);
    node->left = build(nums, l, mid - 1);
    node->right = build(nums, mid + 1, r);
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int nums[20000];
    int n = 0;
    while (head)
    {
        nums[n] = head->val;
        n++;
        head = head->next;
    }
    return build(nums, 0, n - 1);
}
