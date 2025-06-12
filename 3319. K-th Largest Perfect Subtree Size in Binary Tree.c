#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

int sz;

int dfs(struct TreeNode* node,int list[]) //use bitmask
{
    if(node==NULL)
    {
        return 1;
    }
    int l=dfs(node->left,list);
    int r=dfs(node->right,list);
    int sum;
    if((l&1)&&(r&1)&&(l>>1)==(r>>1))
    {
        sum=(l>>1)+(r>>1)+1;
        list[sz]=sum;
        sz++;
        return (sum<<1)+1;
    }
    return 0;
}

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

int kthLargestPerfectSubtree(struct TreeNode* root, int k)
{
    int list[1025]={0};
    sz=0;
    dfs(root,list);
    k--;
    if(sz<=k)
    {
        return -1;
    }
    qsort(list,sz,sizeof(int),cmp);
    return list[k];
}
