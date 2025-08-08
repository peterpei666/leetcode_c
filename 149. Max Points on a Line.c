#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline bool line(int* a,int* b,int* p)
{
    return (a[1]-p[1])*(b[0]-p[0])==(a[0]-p[0])*(b[1]-p[1]);
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxPoints(int** points, int n, int* pointsColSize)
{
    int ans=min(2,n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=2;
            for(int k=0;k<n;k++)
            {
                if(k==i||k==j)
                {
                    continue;
                }
                if(line(points[i],points[j],points[k]))
                {
                    temp++;
                }
            }
            ans=max(ans,temp);
        }
    }
    return ans;
}
