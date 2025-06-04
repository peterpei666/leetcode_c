#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSmallestInteger(int* nums, int n, int value)
{
    int i;
    int mex=0;
    int list[value];
    memset(list,0,sizeof(list));
    for(i=0;i<n;i++)
    {
        list[(nums[i]%value+value)%value]++;
    }
    while(list[mex%value])
    {
        list[mex%value]--;
        mex++;
    }
    return mex;
}
