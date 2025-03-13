#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    struct node* next;
} node;

int direction[4][2]={-1,0,1,0,0,-1,0,1};

node* create(int x,int y)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->row=x;
    newnode->col=y;
    newnode->next=NULL;
    return newnode;
}

void insert(int x,int y,node* root)
{
    node* newnode=create(x,y);
    newnode->next=root->next;
    root->next=(struct node*)newnode;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
    int i,j,d,a=0,count=0,f=0,row,col;
    node root;
    node* temp;
    node* prev;
    root.next=NULL;
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            a|=grid[i][j];
            if(grid[i][j]==2)
            {
                insert(i,j,&root);
            }
        }
    }
    if(a==0)
    {
        return 0;
    }
    while(root.next)
    {
        temp=(node*)root.next;
        root.next=NULL;
        while(temp)
        {
            for(d=0;d<4;d++)
            {
                row=temp->row+direction[d][0];
                col=temp->col+direction[d][1];
                if(row>=0&&row<gridSize&&col>=0&&col<gridColSize[row]&&grid[row][col]==1)
                {
                    grid[row][col]=2;
                    insert(row,col,&root);
                }
            }
            prev=temp;
            temp=(node*)temp->next;
            free(prev);
        }
        count++;
    }
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
        }
    }
    return count-1;
}
