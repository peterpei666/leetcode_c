#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(int masks[],int lens[],int idx,int mask,int n)
{
    if(idx==n)
    {
        return 0;
    }
    int maxlen=dfs(masks,lens,idx+1,mask,n);
    if((mask&masks[idx])==0)
    {
        maxlen=max(maxlen,lens[idx]+dfs(masks,lens,idx+1,mask|masks[idx],n));
    }
    return maxlen;
}

int maxLength(char** arr, int n)
{
    int i,j;
    int masks[n];
    int lens[n];
    for(i=0;i<n;i++)
    {
        lens[i]=(int)strlen(arr[i]);
        masks[i]=0;
        for(j=0;j<lens[i];j++)
        {
            if(masks[i]&(1<<(arr[i][j]-'a')))
            {
                masks[i]=0;
                break;
            }
            masks[i]|=1<<(arr[i][j]-'a');
        }
        if(masks[i]==0)
        {
            lens[i]=0;
        }
    }
    return dfs(masks,lens,0,0,n);
}
