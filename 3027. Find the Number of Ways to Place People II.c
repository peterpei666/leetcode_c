#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int x;
    int y;
} pair;

int compare(const void* p1,const void* p2)
{
    pair* a=(pair*)p1;
    pair* b=(pair*)p2;
    if(a->x!=b->x)
    {
        return a->x-b->x;
    }
    else
    {
        return b->y-a->y;
    }
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize)
{
    int i,j,y,count=0;
    pair* list=(pair*)malloc(sizeof(pair)*pointsSize);
    for(i=0;i<pointsSize;i++)
    {
        list[i].x=points[i][0];
        list[i].y=points[i][1];
    }
    qsort(list,pointsSize,sizeof(pair),compare);
    for(i=0;i<pointsSize;i++)
    {
        y=INT_MIN;
        for(j=i+1;j<pointsSize;j++)
        {
            if(list[i].y>=list[j].y&&y<list[j].y)
            {
                count++;
                y=list[j].y;
            }
        }
    }
    free(list);
    return count;
}
