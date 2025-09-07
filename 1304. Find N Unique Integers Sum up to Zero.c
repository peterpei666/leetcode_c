#include <stdio.h>
#include <stdlib.h>

int* sumZero(int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * n);
    if (n % 2)
    {
        for (int i = 0; i < n; i++)
        {
            ans[i] = i - n / 2;
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            ans[i] = i - n / 2;
        }
        for (int i = n / 2; i < n; i++)
        {
            ans[i] = i - n / 2 + 1;
        }
    }
    *returnSize = n;
    return ans;
}
