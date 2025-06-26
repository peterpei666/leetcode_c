#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int matrixSum(int** nums, int m, int* numsColSize)
{
    int i,j;
    int temp,sum=0;
    int n=numsColSize[0];
    for(i=0;i<m;i++)
    {
        qsort(nums[i],n,sizeof(int),cmp);
    }
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<m;j++)
        {
            temp=max(temp,nums[j][i]);
        }
        sum+=temp;
    }
    return sum;
}
