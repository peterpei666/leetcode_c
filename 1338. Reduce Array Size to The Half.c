#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

int minSetSize(int* arr, int n)
{
    int i;
    int cnt[100000]={0};
    for(i=0;i<n;i++)
    {
        cnt[arr[i]-1]++;
    }
    qsort(cnt,100000,sizeof(int),cmp);
    n/=2;
    for(i=0;i<100000;i++)
    {
        n-=cnt[i];
        if(n<=0)
        {
            return i+1;
        }
    }
    return 0;
}
