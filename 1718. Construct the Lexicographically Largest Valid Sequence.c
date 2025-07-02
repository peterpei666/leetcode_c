#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool dfs(int* best,int idx,int n,int seq[],int mask)
{
    while(idx<2*n-1&&seq[idx])
    {
        idx++;
    }
    if(idx==2*n-1)
    {
        memcpy(best,seq,sizeof(int)*(2*n-1));
        return true;
    }
    int i;
    for(i=n;i>=1;i--)
    {
        if(mask&(1<<i))
        {
            continue;
        }
        if(i>1)
        {
            if(idx+i<2*n-1&&seq[idx+i]==0)
            {
                seq[idx+i]=i;
                seq[idx]=i;
                if(dfs(best,idx+1,n,seq,mask|(1<<i)))
                {
                    return true;
                }
                seq[idx+i]=0;
                seq[idx]=0;
            }
        }
        else
        {
            seq[idx]=1;
            if(dfs(best,idx+1,n,seq,mask|(1<<i)))
            {
                return true;
            }
            seq[idx]=0;
        }
    }
    return false;
}

int* constructDistancedSequence(int n, int* returnSize)
{
    int seq[2*n-1];
    int* best=(int*)malloc(sizeof(int)*(2*n-1));
    memset(seq,0,sizeof(seq));
    dfs(best,0,n,seq,0);
    *returnSize=2*n-1;
    return best;
}
