#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sz,capacity;
int* list;

void dfs(struct TreeNode* node)
{
    if(sz==capacity)
    {
        capacity*=2;
        list=(int*)realloc(list,sizeof(int)*capacity);
    }
    list[sz]=node->val;
    sz++;
    if(node->left)
    {
        dfs(node->left);
    }
    if(node->right)
    {
        dfs(node->right);
    }
}

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
    list=(int*)malloc(sizeof(int)*10);
    sz=0;
    capacity=10;
    if(root1)
    {
        dfs(root1);
    }
    if(root2)
    {
        dfs(root2);
    }
    qsort(list,sz,sizeof(int),cmp);
    *returnSize=sz;
    return list;
}
