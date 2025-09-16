#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int gcd(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int* replaceNonCoprimes(int* nums, int n, int* returnSize)
{
    int memo[n];
    memo[0] = nums[0];
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        int temp = nums[i];
        while (k > 0 && gcd(memo[k - 1], temp) != 1)
        {
            temp = memo[k - 1] / gcd(memo[k - 1], temp) * temp;
            k--;
        }
        memo[k] = temp;
        k++;
    }
    int* ans = (int*)malloc(sizeof(int) * k);
    memcpy(ans, memo, sizeof(int) * k);
    *returnSize = k;
    return ans;
}
