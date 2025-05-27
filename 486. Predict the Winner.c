#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(int* nums,int i,int j)
{
    if(i==j)
    {
        return nums[i];
    }
    int sum1=nums[i]-dfs(nums,i+1,j);
    int sum2=nums[j]-dfs(nums,i,j-1);
    return max(sum1,sum2);
}

bool predictTheWinner(int* nums, int n)
{
    return dfs(nums,0,n-1)>=0;
}
