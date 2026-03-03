#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tree[100005];
int MAX = 100001;

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

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int createSortedArray(int* instructions, int n)
{
    memset(tree, 0, sizeof(tree));
    long long ans = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int left = query(instructions[i] - 1);
        int right = i - query(instructions[i]);
        ans += min(left, right);
        update(instructions[i]);
    }
    return ans % mod;
}
