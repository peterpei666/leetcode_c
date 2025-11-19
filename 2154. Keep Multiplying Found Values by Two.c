#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findFinalValue(int* nums, int n, int original)
{
    bool mp[1001];
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = true;
    }
    while (original <= 1000 && mp[original])
    {
        original <<= 1;
    }
    return original;
}
