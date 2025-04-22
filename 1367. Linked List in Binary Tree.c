#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool match(struct ListNode* head, struct TreeNode* node)
{
    if(node==NULL)
    {
        return false;
    }
    if(node->val==head->val)
    {
        if(head->next==NULL)
        {
            return true;
        }
        else
        {
            return match(head->next,node->left)||match(head->next,node->right);
        }
    }
    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root)
{
    if(match(head,root))
    {
        return true;
    }
    else if(root==NULL)
    {
        return false;
    }
    else
    {
        return isSubPath(head,root->left)||isSubPath(head,root->right);
    }
}
