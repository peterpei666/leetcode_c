#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 13

typedef struct
{
    unsigned long long list[N / 8 + 1];
} bitset;

static inline void set(bitset* a, int i)
{
    a->list[i >> 6] |= 1ULL << (i & 63);
}

static inline void reset_all(bitset* a)
{
    memset(a->list, 0, N);
}

static inline bool test(const bitset* a, int i)
{
    return (a->list[i >> 6] & (1ULL << (i & 63))) != 0;
}

int minDeletionSize(char** strs, int n)
{
    int m = (int)strlen(strs[0]);
    bitset ordered;
    reset_all(&ordered);
    int unordered = n - 1;
    int ans = 0;
    for (int c = 0; c < m && unordered > 0; c++)
    {
        bool f = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (!test(&ordered, i) && strs[i][c] > strs[i + 1][c])
            {
                f = true;
                break;
            }
        }
        if (f)
        {
            ans++;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (!test(&ordered, i) && strs[i][c] < strs[i + 1][c])
                {
                    set(&ordered, i);
                    unordered--;
                }
            }
        }
    }
    return ans;
}
