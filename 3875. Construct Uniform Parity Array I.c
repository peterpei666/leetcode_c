#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool uniformArray(int* nums1, int n)
{
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] & 1)
        {
            odd++;
        }
    }
    bool valid_odd = true;
    bool valid_even = true;
    for (int i = 0; i < n; i++)
    {
        if (nums1[i] & 1)
        {
            valid_even &= odd > 1;
        }
        else
        {
            valid_odd &= odd > 0;
        }
    }
    return valid_odd || valid_even;
}
