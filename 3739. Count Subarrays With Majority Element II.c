#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tree[200005];
int MAX = 200002;

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

long long countMajoritySubarrays(int* nums, int n, int target)
{
    memset(tree, 0, sizeof(tree));
    int cur = 0;
    long long ans = 0;
    update(0 + 100001);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            cur++;
        }
        else
        {
            cur--;
        }
        ans += query(cur - 1 + 100001);
        update(cur + 100001);
    }
    return ans;
}
