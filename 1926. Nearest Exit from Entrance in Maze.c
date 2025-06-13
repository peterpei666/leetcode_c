#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct state
{
    int x;
    int y;
    int dis;
} state;

typedef struct queue
{
    state* list;
    int head;
    int sz;
    int capacity;
} queue;

queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(state*)malloc(sizeof(state)*100);
    q->head=0;
    q->sz=0;
    q->capacity=100;
    return q;
}

queue* reallocation(queue* q)
{
    int size=q->sz-q->head;
    q->capacity*=2;
    state* new=(state*)malloc(sizeof(state)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(state)*size);
    free(q->list);
    q->sz-=q->head;
    q->head=0;
    q->list=new;
    return q;
}

inline void push(queue* q,int x,int y,int dis)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=(state){x,y,dis};
    q->sz++;
}

inline state front(queue* q)
{
    return q->list[q->head];
}

inline void pop(queue* q)
{
    q->head++;
}
 
inline bool empty(queue* q)
{
    return q->head==q->sz;
}

inline void clear(queue* q)
{
    free(q->list);
    free(q);
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize)
{
    int x,y,nx,ny,dis,d;
    int m=mazeSize;
    int n=mazeColSize[0];
    int dir[4][2]={-1,0,0,-1,0,1,1,0};
    state temp;
    queue* q=initialize();
    push(q,entrance[0],entrance[1],0);
    maze[entrance[0]][entrance[1]]='+';
    while(!empty(q))
    {
        temp=front(q);
        pop(q);
        x=temp.x;
        y=temp.y;
        dis=temp.dis;
        for(d=0;d<4;d++)
        {
            nx=x+dir[d][0];
            ny=y+dir[d][1];
            if((nx<0||nx>=m||ny<0||ny>=n)&&dis)
            {
                clear(q);
                return dis;
            }
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&maze[nx][ny]!='+')
            {
                maze[nx][ny]='+';
                push(q,nx,ny,dis+1);
            }
        }
    }
    clear(q);
    return -1;
}
