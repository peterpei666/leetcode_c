#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int minRectanglesToCoverPoints(int** points, int pointsSize, int* pointsColSize, int w)
{
    int i,ans=1,cur;
    int x[100000];
    for(i=0;i<pointsSize;i++)
    {
        x[i]=points[i][0];
    }
    qsort(x,pointsSize,sizeof(int),cmp);
    cur=x[0];
    for(i=1;i<pointsSize;i++)
    {
        if(x[i]>cur+w)
        {
            ans++;
            cur=x[i];
        }
    }
    return ans;
}
