#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int mini(int a,int b)
{
    return a>b?b:a;
}

void initialize(int p[31])
{
    int i;
    for(i=0;i<31;i++)
    {
        p[i]=-1;
    }
}

void insert(int p[31],int index,int n)
{
    int i=0;
    while(n)
    {
        if(n&1)
        {
            p[i]=index;
        }
        n>>=1;
        i++;
    }
}

int see(int p[31],int index)
{
    int i,m=0;
    for(i=0;i<31;i++)
    {
        if(p[i]==index)
        {
            m+=(1<<i);
        }
    }
    return m;
}

void extract(int p[31],int index)
{
    int i;
    for(i=0;i<31;i++)
    {
        if(p[i]==index)
        {
            p[i]=-1;
        }
    }
}

int minimumSubarrayLength(int* nums, int numsSize, int k)
{
    int p[31];
    int a=0,i,j=0,min=numsSize+1;
    initialize(p);
    for(i=0;i<numsSize;i++)
    {
        a|=nums[i];
        insert(p,i,nums[i]);
        if(a>=k)
        {
            min=mini(min,i-j);
        }
        while(j<i&&(a-see(p,j))>=k)
        {
            a-=see(p,j);
            extract(p,j);
            j++;
            min=mini(min,i-j);
        }
    }
    if(min==numsSize+1)
    {
        return -1;
    }
    else
    {
        return min+1;
    }
}
