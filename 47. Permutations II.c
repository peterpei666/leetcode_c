#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int mp[], int n, int idx, int temp[], int*** ans, int* capacity, int* sz)
{
    if (idx == n)
    {
        if (*sz == *capacity)
        {
            *capacity *= 2;
            *ans = (int**)realloc(*ans, sizeof(int*) * (*capacity));
        }
        int* t = (int*)malloc(sizeof(int) * n);
        memcpy(t, temp, sizeof(int) * n);
        (*ans)[*sz] = t;
        (*sz)++;
    }
    for (int i = 0; i <= 20; i++)
    {
        if (mp[i] > 0)
        {
            mp[i]--;
            temp[idx] = i - 10;
            dfs(mp, n, idx + 1, temp, ans, capacity, sz);
            mp[i]++;
        }
    }
}

int** permuteUnique(int* nums, int n, int* returnSize, int** returnColumnSizes)
{
    int capacity = 8;
    int sz = 0;
    int mp[21] = {0};
    int temp[8];
    int** ans = (int**)malloc(sizeof(int*) * 8);
    for (int i = 0; i < n; i++)
    {
        mp[nums[i] + 10]++;
    }
    dfs(mp, n, 0, temp, &ans, &capacity, &sz);
    *returnSize = sz;
    *returnColumnSizes = (int*)malloc(sizeof(int) * sz);
    for (int i = 0; i < sz; i++)
    {
        (*returnColumnSizes)[i] = n;
    }
    return ans;
}
