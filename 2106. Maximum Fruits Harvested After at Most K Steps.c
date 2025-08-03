#include <stdio.h>
#include <stdlib.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline int step(int l,int r,int start,int** fruits)
{
    if(fruits[r][0]<=start) return start-fruits[l][0];
    else if(fruits[l][0]>=start) return fruits[r][0]-start;
    else return min(abs(fruits[l][0]-start),abs(fruits[r][0]-start))+fruits[r][0]-fruits[l][0];
}

int maxTotalFruits(int** fruits, int n, int* fruitsColSize, int startPos, int k)
{
    int l=0,r=0;
    int temp=0,ans=0;
    while(r<n)
    {
        temp+=fruits[r][1];
        while(l<=r&&step(l,r,startPos,fruits)>k)
        {
            temp-=fruits[l][1];
            l++;
        }
        ans=max(ans,temp);
        r++;
    }
    return ans;
}
