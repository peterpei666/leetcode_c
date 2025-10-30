#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* plusOne(int* digits, int m, int* returnSize)
{
    int n = m - 1;
    bool add = true;
    while (n >= 0 && add)
    {
        digits[n]++;
        add = digits[n] >= 10;
        digits[n] %= 10;
        n--;
    }
    if (add)
    {
        int* ans = (int*)malloc(sizeof(int) * (m + 1));
        ans[0] = 1;
        memcpy(ans + 1, digits, sizeof(int) * m);
        *returnSize = m + 1;
        return ans;
    }
    *returnSize = m;
    return digits;
}
