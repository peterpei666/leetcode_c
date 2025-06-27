#include <stdio.h>
#include <stdlib.h>

int* goodDaysToRobBank(int* security, int n, int time, int* returnSize)
{
    int i,k=0,sz=10;
    int prefix[n];
    int suffix[n];
    int* ret=(int*)malloc(sizeof(int)*sz);
    prefix[0]=1;
    for(i=1;i<n;i++)
    {
        if(security[i]<=security[i-1])
        {
            prefix[i]=prefix[i-1]+1;
        }
        else
        {
            prefix[i]=1;
        }
    }
    suffix[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        if(security[i]<=security[i+1])
        {
            suffix[i]=suffix[i+1]+1;
        }
        else
        {
            suffix[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(prefix[i]>time&&suffix[i]>time)
        {
            if(k>=sz)
            {
                sz*=2;
                ret=(int*)realloc(ret,sizeof(int)*sz);
            }
            ret[k]=i;
            k++;
        }
    }
    *returnSize=k;
    return ret;
}
