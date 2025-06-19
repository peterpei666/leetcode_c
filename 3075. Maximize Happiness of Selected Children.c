#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

long long maximumHappinessSum(int* happiness,int n,int k)
{
    int i;
    long long sum=0;
    qsort(happiness,n,sizeof(int),cmp);
    for(i=0;i<n&&i<k;i++)
    {
        if(happiness[i]<i)
        {
            break;
        }
        sum+=(long long)happiness[i]-i;
    }
    return sum;
}
