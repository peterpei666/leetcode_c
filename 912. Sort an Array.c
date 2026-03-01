#include <stdio.h>
#include <stdlib.h>

static inline void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_max(int* list, int i, int sz)
{
    int largest = i;
    int l, r;
    while (1)
    {
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < sz && list[l] > list[largest])
        {
            largest = l;
        }
        if (r < sz && list[r] > list[largest])
        {
            largest = r;
        }
        if (i == largest)
        {
            break;
        }
        swap(&list[i], &list[largest]);
        i = largest;
    }
}

int* sortArray(int* nums, int n, int* returnSize)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify_max(nums, i, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(&nums[0], &nums[i]);
        heapify_max(nums, 0, i);
    }
    *returnSize = n;
    return nums;
}
