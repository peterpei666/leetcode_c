#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
{
    int i,ret=0;
    int* list=(int*)malloc(sizeof(int)*pointsSize);
    for(i=0;i<pointsSize;i++)
    {
        list[i]=points[i][0];
    }
    qsort(list,pointsSize,sizeof(int),cmp);
    for(i=1;i<pointsSize;i++)
    {
        ret=maxi(ret,list[i]-list[i-1]);
    }
    return ret;
}
