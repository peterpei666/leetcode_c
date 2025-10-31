#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 100

typedef struct
{
    unsigned long long list[N / 8 + 1];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list, 0, N);
}

static inline void set(bitset* a, int i)
{
    a->list[i >> 6] |= 1ULL << (i & 63);
}

static inline bool test(const bitset* a, int i)
{
    return (a->list[i >> 6] & (1ULL << (i & 63))) != 0;
}

int* getSneakyNumbers(int* nums, int n, int* returnSize)
{
    bitset mp;
    reset_all(&mp);
    int k = 0;
    int* ans = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < n; i++)
    {
        if (test(&mp, nums[i]))
        {
            ans[k] = nums[i];
            k++;
        }
        else
        {
            set(&mp, nums[i]);
        }
    }
    *returnSize = 2;
    return ans;
}
