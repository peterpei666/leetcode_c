#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int trap(int* height, int n)
{
    int i;
    int ans=0;
    int l[n],r[n];
    l[0]=height[0];
    for(i=1;i<n;i++)
    {
        l[i]=max(l[i-1],height[i]);
    }
    r[n-1]=height[n-1];
    for(i=n-2;i>=0;i--)
    {
        r[i]=max(r[i+1],height[i]);
    }
    for(i=1;i<n-1;i++)
    {
        if(height[i]<min(r[i],l[i]))
        {
            ans+=min(r[i],l[i])-height[i];
        }
    }
    return ans;
}
