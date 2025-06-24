#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[125];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int* findKDistantIndices(int* nums, int n, int key, int k, int* returnSize)
{
    int i,j;
    int* ret=(int*)malloc(sizeof(int)*n);
    memset(visited,0,sizeof(visited));
    for(i=0;i<n;i++)
    {
        if(nums[i]==key)
        {
            for(int j=max(0,i-k);j<=min(i+k,n-1);j++)
            {
                set(j);
            }
        }
    }
    for(i=0,j=0;i<n;i++)
    {
        if(test(i))
        {
            ret[j]=i;
            j++;
        }
    }
    *returnSize=j;
    return ret;
}
