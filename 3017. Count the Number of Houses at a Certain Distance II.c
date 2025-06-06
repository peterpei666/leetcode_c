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

inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

long long* countOfPairs(int n, int x, int y, int* returnSize)
{
    int i,temp;
    long long* list=(long long*)calloc(n,sizeof(long long));
    if(x>y)
    {
        swap(&x,&y);
    }
    for(i=1;i<=n;i++)
    {
        list[0]+=2;
        list[min(i-1,abs(i-y)+x)]--;
        list[min(n-i,abs(i-x)+n-y+1)]--;
        list[min(abs(i-x),abs(i-y)+1)]++;
        list[min(abs(i-x)+1,abs(i-y))]++;
        temp=max(x-i,0)+max(i-y,0);
        list[temp+(y-x)/2]--;
        list[temp+(y-x+1)/2]--;
    }
    for(i=1;i<n;i++)
    {
        list[i]+=list[i-1];
    }
    *returnSize=n;
    return list;
}
