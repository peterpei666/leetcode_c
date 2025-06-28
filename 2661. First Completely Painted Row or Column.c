#include <stdio.h>
#include <stdlib.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize)
{
    int i,j;
    int m=matSize;
    int n=matColSize[0];
    int ans1=m*n,ans2=m*n;
    int temp;
    int list[m*n+1];
    for(i=0;i<m*n;i++)
    {
        list[arr[i]]=i;
    }
    for(i=0;i<m;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            temp=max(temp,list[mat[i][j]]);
        }
        ans1=min(ans1,temp);
    }
    for(j=0;j<n;j++)
    {
        temp=0;
        for(i=0;i<m;i++)
        {
            temp=max(temp,list[mat[i][j]]);
        }
        ans2=min(ans2,temp);
    }
    return min(ans1,ans2);
}
