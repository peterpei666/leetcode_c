#include <stdio.h>
#include <stdlib.h>

void sortColors(int* nums, int n)
{
    int p;
    int c[3]={0};
    for(p=0;p<n;p++)
    {
        c[nums[p]]++;
    }
    p=0;
    while(c[0])
    {
        nums[p]=0;
        c[0]--;
        p++;
    }
    while(c[1])
    {
        nums[p]=1;
        c[1]--;
        p++;
    }
    while(c[2])
    {
        nums[p]=2;
        c[2]--;
        p++;
    }
}
