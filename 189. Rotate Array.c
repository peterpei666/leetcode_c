#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int* nums, int n, int k)
{
    int i;
    int list[n];
    k%=n;
    for(i=0;i<n;i++)
    {
        list[(i+k)%n]=nums[i];
    }
    memcpy(nums,list,sizeof(list));
}
