#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define N 100000

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

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

static inline long long min(long long a, long long b)
{
    return a < b ? a : b;
}

static inline long long absll(long long a)
{
    return a > 0 ? a : -a;
}

long long splitArray(int* nums, int n)
{
    bitset left;
    reset_all(&left);
    bitset right;
    reset_all(&right);
    set(&left, 0);
    for (int i = 1; i < n && nums[i] > nums[i - 1]; i++)
    {
        set(&left, i);
    }
    set(&right, n - 1);
    for (int i = n - 2; i >= 0 && nums[i] > nums[i + 1]; i--)
    {
        set(&right, i);
    }
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }
    long long sum = 0;
    long long ans = LLONG_MAX;
    for (int i = 0; i < n - 1 && test(&left, i); i++)
    {
        sum += nums[i];
        if (test(&right, i + 1))
        {
            ans = min(ans, absll(sum - (total - sum)));
        }
    }
    if (ans == LLONG_MAX)
    {
        ans = -1;
    }
    return ans;
}
