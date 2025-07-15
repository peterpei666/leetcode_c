#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mp[201];

int cmp(const void* p1,const void* p2)
{
    int a=*(int*)p1;
    int b=*(int*)p2;
    return mp[a+100]==mp[b+100]?b-a:mp[a+100]-mp[b+100];
}

int* frequencySort(int* nums, int n, int* returnSize)
{
    memset(mp,0,sizeof(mp));
    for(int i=0;i<n;i++)
    {
        mp[nums[i]+100]++;
    }
    qsort(nums,n,sizeof(int),cmp);
    *returnSize=n;
    return nums;
}
