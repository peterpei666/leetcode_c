#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int maxCollectedFruits(int** fruits, int n, int* fruitsColSize)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=fruits[i][i];
    }
    int pre[n];
    int cur[n];
    memset(pre,0x80,sizeof(pre));
    memset(cur,0x80,sizeof(cur));
    pre[n-1]=fruits[0][n-1];
    for(int i=1;i<n-1;i++)
    {
        for(int j=max(i+1,n-i-1);j<n;j++)
        {
            int best=pre[j];
            if(j>=1)
            {
                best=max(best,pre[j-1]);
            }
            if(j<n-1)
            {
                best=max(best,pre[j+1]);
            }
            cur[j]=best+fruits[i][j];
        }
        memcpy(pre,cur,sizeof(cur));
    }
    ans+=pre[n-1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(&fruits[i][j],&fruits[j][i]);
        }
    }
    memset(pre,0x80,sizeof(pre));
    memset(cur,0x80,sizeof(cur));
    pre[n-1]=fruits[0][n-1];
    for(int i=1;i<n-1;i++)
    {
        for(int j=max(i+1,n-i-1);j<n;j++)
        {
            int best=pre[j];
            if(j>=1)
            {
                best=max(best,pre[j-1]);
            }
            if(j<n-1)
            {
                best=max(best,pre[j+1]);
            }
            cur[j]=best+fruits[i][j];
        }
        memcpy(pre,cur,sizeof(cur));
    }
    ans+=pre[n-1];
    return ans;
}
