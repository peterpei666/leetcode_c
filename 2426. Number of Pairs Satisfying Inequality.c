#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tree[50005];
int MAX = 50001;

void update(int i)
{
    for (; i < MAX; i += i & -i)
    {
        tree[i]++;
    }
}

int query(int i)
{
    int ans = 0;
    for (; i > 0; i -= i & -i)
    {
        ans += tree[i];
    }
    return ans;
}

long long numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int diff)
{
    int n = nums1Size;
    memset(tree, 0, sizeof(tree));
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t = nums1[i] - nums2[i] + 20001;
        ans += query(t + diff);
        update(t);
    }
    return ans;
}
