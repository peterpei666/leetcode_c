#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ord[101];

int cmp(const void* p1, const void* p2)
{
    return ord[*(int*)p1] - ord[*(int*)p2];
}

int* recoverOrder(int* order, int n, int* friends, int friendsSize, int* returnSize)
{
    memset(ord, 0, sizeof(ord));
    for (int i = 0; i < n; i++)
    {
        ord[order[i]] = i;
    }
    qsort(friends, friendsSize, sizeof(int), cmp);
    *returnSize = friendsSize;
    return friends;
}
