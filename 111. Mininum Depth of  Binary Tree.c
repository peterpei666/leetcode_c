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

int minDepth(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int depth,head=0,tail=0;
    struct QueueNode queue[10000];
    struct QueueNode temp;
    queue[tail]=(struct QueueNode){root,1};
    tail++;
    while(head<tail)
    {
        temp=queue[head];
        head++;
        if(temp.node->left==NULL&&temp.node->right==NULL)
        {
            return temp.depth;
        }
        if(temp.node->left)
        {
            queue[tail]=(struct QueueNode){temp.node->left,temp.depth+1};
            tail++;
        }
        if(temp.node->right)
        {
            queue[tail]=(struct QueueNode){temp.node->right,temp.depth+1};
            tail++;
        }
    }
    return -1;
}
