#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    for (int i = 0; i <= n; i++)
    {
        ans[i] = __builtin_popcount(i);
    }
    return ans;
}
