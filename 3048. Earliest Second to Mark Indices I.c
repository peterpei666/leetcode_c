#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[250];

bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

bool search(int n,int* nums,int* changeIndices,int idx)
{
    if(idx<n)
    {
        return false;
    }
    int i;
    int cnt=0,k=0;
    int last[n];
    memset(visited,0,sizeof(visited));
    for(i=0;i<idx;i++)
    {
        last[changeIndices[i]-1]=i;
        if(!test(changeIndices[i]-1))
        {
            set(changeIndices[i]-1);
            k++;
        }
    }
    if(k<n)
    {
        return false;
    }
    for(i=0;i<idx;i++)
    {
        if(i==last[changeIndices[i]-1])
        {
            cnt-=nums[changeIndices[i]-1];
            if(cnt<0)
            {
                return false;
            }
        }
        else
        {
            cnt++;
        }
    }
    return true;
}

int earliestSecondToMarkIndices(int* nums, int n, int* changeIndices, int m)
{
    int l=0,r=m+1,mid;
    while(l<r)
    {
        mid=l+(r-l)/2;
        if(search(n,nums,changeIndices,mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r==m+1?-1:r;
}
