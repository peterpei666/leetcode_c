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
    found[node->val+10000]=true;
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
    node->val=list[node->val+10000];
    if(node->left)
    {
        change(node->left,list);
    }
    if(node->right)
    {
        change(node->right,list);
    }
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    int i;
    bool* found=(bool*)malloc(sizeof(bool)*20001);
    int* list=(int*)malloc(sizeof(int)*20002);
    memset(found,false,20001);
    insert(root,found);
    list[20001]=0;
    for(i=20000;i>=0;i--)
    {
        if(found[i])
        {
            list[i]=list[i+1]+i-10000;
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

