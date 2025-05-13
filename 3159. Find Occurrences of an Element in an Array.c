#include <stdio.h>
#include <stdlib.h>

int* occurrencesOfElement(int* nums, int n, int* queries, int q, int x, int* returnSize)
{
    int c=0,i;
    int list[n];
    for(i=0;i<n;i++)
    {
        if(nums[i]==x)
        {
            list[c]=i;
            c++;
        }
    }
    int* ret=(int*)malloc(sizeof(int)*q);
    for(i=0;i<q;i++)
    {
        if(queries[i]>c)
        {
            ret[i]=-1;
        }
        else
        {
            ret[i]=list[queries[i]-1];
        }
    }
    *returnSize=q;
    return ret;
}
