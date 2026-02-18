#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* toggleLightBulbs(int* bulbs, int n, int* returnSize)
{
    bool mp[101] = {false};
    for (int i = 0; i < n; i++)
    {
        mp[bulbs[i]] ^= 1;
    }
    int* ans = (int*)malloc(sizeof(int) * n);
    int sz = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (mp[i])
        {
            ans[sz++] = i;
        }
    }
    *returnSize = sz;
    return ans;
}
