#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize)
{
    int i,j,k;
    int m=matSize;
    int n=matColSize[0];
    int list[m+n][mini(m,n)];
    int sz[m+n];
    memset(sz,0,sizeof(sz));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            list[i+j][sz[i+j]]=mat[i][j];
            sz[i+j]++;
        }
    }
    int* ret=(int*)malloc(sizeof(int)*m*n);
    k=0;
    for(i=0;i<m+n&&k<m*n;i++)
    {
        if(i%2==0)
        {
            for(j=sz[i]-1;j>=0;j--)
            {
                ret[k]=list[i][j];
                k++;
            }
        }
        else
        {
            for(j=0;j<sz[i];j++)
            {
                ret[k]=list[i][j];
                k++;
            }
        }
    }
    *returnSize=m*n;
    return ret;
}
