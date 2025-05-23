#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maxsum(int* nums,int n,int idx,int even,int k,long long memo[][2])
{
    if(idx==n)
    {
        return even?0:INT_MIN;
    }
    if(memo[idx][even]!=-1)
    {
        return memo[idx][even];
    }
    long long xor=(nums[idx]^k)+maxsum(nums,n,idx+1,even^1,k,memo);
    long long noxor=nums[idx]+maxsum(nums,n,idx+1,even,k,memo);
    memo[idx][even]=maxi(xor,noxor);
    return memo[idx][even];
}

long long maximumValueSum(int* nums, int n, int k, int** edges, int edgesSize, int* edgesColSize)
{
    long long memo[n][2];
    memset(memo,-1,sizeof(memo));
    return maxsum(nums,n,0,1,k,memo);
}
