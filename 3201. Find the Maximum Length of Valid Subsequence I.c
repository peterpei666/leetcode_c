#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumLength(int* nums, int n)
{
    int i;
    int allodd=0;
    int alleven=0;
    int oddeven=0;
    int evenodd=0;
    bool odd;
    for(i=0;i<n;i++)
    {
        if(nums[i]%2)
        {
            allodd++;
        }
        else
        {
            alleven++;
        }
    }
    odd=true;
    for(i=0;i<n;i++)
    {
        if(nums[i]%2==odd)
        {
            odd^=1;
            oddeven++;
        }
    }
    odd=false;
    for(i=0;i<n;i++)
    {
        if(nums[i]%2==odd)
        {
            odd^=1;
            evenodd++;
        }
    }
    return max(max(allodd,alleven),max(oddeven,evenodd));
}
