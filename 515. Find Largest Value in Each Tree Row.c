#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
 
struct QueueNode
{
    struct TreeNode* node;
    int depth;
};

int* largestValues(struct TreeNode* root, int* returnSize)
{
    if(root==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    int head=0,tail=0,depth=0,capacity=1,i;
    struct QueueNode queue[30000];
    struct TreeNode* temp;
    int* ret=(int*)malloc(1000*sizeof(int));
    for(i=0;i<1000;i++)
    {
        ret[i]=-2147483648;
    }
    queue[0]=(struct QueueNode){root,0};
    tail++;
    while(head<tail)
    {
        temp=queue[head].node;
        depth=queue[head].depth;
        head++;
        if(temp->val>ret[depth])
        {
            ret[depth]=temp->val;
        }
        if(temp->left)
        {
            queue[tail]=(struct QueueNode){temp->left,depth+1};
            tail++;
        }
        if(temp->right)
        {
            queue[tail]=(struct QueueNode){temp->right,depth+1};
            tail++;
        }
    }
    *returnSize=depth+1;
    return ret;
}
