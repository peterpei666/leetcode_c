#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[12501];

bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

bool validPartition(int* nums, int n)
{
    int i;
    memset(visited,0,sizeof(visited));
    set(0);
    for(int i=2;i<=n;i++)
    {
        if(nums[i-2]==nums[i-1]&&test(i-2))
        {
            set(i);
        }
        if(i>=3&&nums[i-2]==nums[i-1]&&nums[i-3]==nums[i-1]&&test(i-3))
        {
            set(i);
        }
        if(i>=3&&nums[i-2]+1==nums[i-1]&&nums[i-3]+1==nums[i-2]&&test(i-3))
        {
            set(i);
        }
    }
    return test(n);
}
