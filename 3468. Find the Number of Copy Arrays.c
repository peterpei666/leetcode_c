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

int countArrays(int* original, int n, int** bounds, int boundsSize, int* boundsColSize)
{
    int i;
    int m1=bounds[0][0];
    int m2=bounds[0][1];
    for(i=1;i<n;i++)
    {
        m1=m1+original[i]-original[i-1];
        m2=m2+original[i]-original[i-1];
        m1=max(m1,bounds[i][0]);
        m2=min(m2,bounds[i][1]);
        if(m1>m2)
        {
            return 0;
        }
    }
    return m2-m1+1;
}
