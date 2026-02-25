#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return __builtin_popcount(*(int*)p1) == __builtin_popcount(*(int*)p2) ? *(int*)p1 - *(int*)p2 : __builtin_popcount(*(int*)p1) - __builtin_popcount(*(int*)p2);
}

int* sortByBits(int* arr, int n, int* returnSize)
{
    qsort(arr, n, sizeof(int), cmp);
    *returnSize = n;
    return arr;
}
