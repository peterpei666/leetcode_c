#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* gardenNoAdj(int n, int** paths, int pathsSize, int* pathsColSize, int* returnSize)
{
    int i,j,mask;
    int c[n];
    int path[n][3];
    int* ret=(int*)malloc(sizeof(int)*n);
    memset(c,0,sizeof(c));
    memset(path,-1,sizeof(path));
    for(i=0;i<pathsSize;i++)
    {
        path[paths[i][0]-1][c[paths[i][0]-1]]=paths[i][1]-1;
        path[paths[i][1]-1][c[paths[i][1]-1]]=paths[i][0]-1;
        c[paths[i][0]-1]++;
        c[paths[i][1]-1]++;
    }
    for(i=0;i<n;i++)
    {
        mask=0;
        for(j=0;j<3;j++)
        {
            if(path[i][j]!=-1&&path[i][j]<i)
            {
                mask|=1<<ret[path[i][j]];
            }
        }
        for(j=1;j<=4;j++)
        {
            if((mask&(1<<j))==0)
            {
                ret[i]=j;
                break;
            }
        }
    }
    *returnSize=n;
    return ret;
}
