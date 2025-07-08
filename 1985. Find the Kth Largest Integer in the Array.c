#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    char* a=*((char**)p1);
    char* b=*((char**)p2);
    int l1=(int)strlen(a);
    int l2=(int)strlen(b);
    if(l1!=l2)
    {
        return l2-l1;
    }
    return strcmp(b,a);
}

char* kthLargestNumber(char** nums, int n, int k)
{
    qsort(nums,n,sizeof(char*),cmp);
    return nums[k-1];
}
