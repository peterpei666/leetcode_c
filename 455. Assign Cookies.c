#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    int i,j,count;
    qsort(g,gSize,sizeof(int),compare);
    qsort(s,sSize,sizeof(int),compare);
    i=gSize-1;
    j=sSize-1;
    count=0;
    while(i>=0&&j>=0)
    {
        if(s[j]>=g[i])
        {
            count++;
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }
    return count;
}
