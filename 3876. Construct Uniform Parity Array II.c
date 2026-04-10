#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

bool uniformArray(int* nums1, int n)
{
    int odd = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] & 1)
        {
            odd = min(odd, nums1[i]);
        }
    }
    bool valid_odd = true;
    bool valid_even = true;
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] & 1)
        {
            valid_even &= nums1[i] > odd;
        }
        else
        {
            valid_odd &= nums1[i] > odd;
        }
    }
    return valid_odd || valid_even;
}
