#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k)
{
    int n=0,i,j,m;
    long long ans=0;
    for(i=0;i<gridSize;i++)
    {
        n+=limits[i];
        qsort(grid[i],gridColSize[i],sizeof(int),cmp);
    }
    int list[n+1];
    for(i=0,m=0;i<gridSize;i++)
    {
        for(j=0;j<limits[i];j++)
        {
            list[m]=grid[i][j];
            m++;
        }
    }
    qsort(list,n,sizeof(int),cmp);
    for(i=0;i<k;i++)
    {
        ans+=list[i];
    }
    return ans;
}
