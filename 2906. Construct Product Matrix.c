#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes)
{
    int m=gridSize,n=gridColSize[0];
    int i,j;
    long long pre=1,suf=1;
    int** ret=(int**)malloc(sizeof(int*)*m);
    *returnSize=m;
    (*returnColumnSizes)=(int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
        (*returnColumnSizes)[i]=n;
        ret[i]=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            ret[i][j]=1;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            ret[i][j]*=pre;
            ret[i][j]%=12345;
            ret[m-1-i][n-1-j]*=suf;
            ret[m-1-i][n-1-j]%=12345;
            pre*=(long long)grid[i][j];
            pre%=12345;
            suf*=(long long)grid[m-1-i][n-1-j];
            suf%=12345;
        }
    }
    return ret;
}
