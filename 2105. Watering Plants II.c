#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB)
{
    int i=0,j=plantsSize-1;
    int ret=0;
    int c1=capacityA,c2=capacityB;
    while(i<j)
    {
        ret+=(c1<plants[i])+(c2<plants[j]);
        c1=c1<plants[i]?capacityA:c1;
        c2=c2<plants[j]?capacityB:c2;
        c1-=plants[i];
        c2-=plants[j];
        i++;
        j--;
    }
    ret+=(i==j&&maxi(c1,c2)<plants[i]);
    return ret;
}
