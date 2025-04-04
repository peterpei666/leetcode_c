#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void insert(struct TreeNode* node,bool* found)
{
    found[node->val]=true;
    if(node->left)
    {
        insert(node->left,found);
    }
    if(node->right)
    {
        insert(node->right,found);
    }
}

void change(struct TreeNode* node,int* list)
{
    node->val=list[node->val];
    if(node->left)
    {
        change(node->left,list);
    }
    if(node->right)
    {
        change(node->right,list);
    }
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int i;
    bool* found=(bool*)malloc(sizeof(bool)*101);
    int* list=(int*)malloc(sizeof(int)*102);
    memset(found,false,101);
    insert(root,found);
    list[101]=0;
    for(i=100;i>=0;i--)
    {
        if(found[i])
        {
            list[i]=list[i+1]+i;
        }
        else
        {
            list[i]=list[i+1];
        }
    }
    change(root,list);
    free(found);
    free(list);
    return root;
}

