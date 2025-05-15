#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair
{
    int x;
    int y;
} pair;

typedef struct queue
{
    pair* list;
    int head;
    int sz;
    int capacity;
} queue;

queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(pair*)malloc(sizeof(pair)*100);
    q->head=0;
    q->sz=0;
    q->capacity=100;
    return q;
}

queue* reallocation(queue* q)
{
    q->capacity*=2;
    pair* new=(pair*)malloc(sizeof(pair)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(pair)*(q->sz-q->head));
    q->sz-=q->head;
    q->head=0;
    free(q->list);
    q->list=new;
    return q;
}

void push(queue* q,int a,int b)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=(pair){a,b};
    q->sz++;
}

pair top(queue* q)
{
    return q->list[q->head];
}

void pop(queue* q)
{
    q->head++;
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes)
{
    int nx,ny,d,i,j;
    int m=matSize;
    int n=matColSize[0];
    const int INF=1000000;
    int dir[4][2]={-1,0,0,-1,1,0,0,1};
    pair temp;
    queue* q=initialize();
    int** height=(int**)malloc(sizeof(int*)*m);
    *returnSize=m;
    *returnColumnSizes=(int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
        height[i]=(int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i]=n;
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                height[i][j]=0;
                push(q,i,j);
            }
            else
            {
                height[i][j]=INF;
            }
        }
    }
    while(q->sz>q->head)
    {
        temp=top(q);
        pop(q);
        for(d=0;d<4;d++)
        {
            nx=temp.x+dir[d][0];
            ny=temp.y+dir[d][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&height[nx][ny]>height[temp.x][temp.y]+1)
            {
                height[nx][ny]=height[temp.x][temp.y]+1;
                push(q,nx,ny);
            }
        }
    }
    return height;
}
