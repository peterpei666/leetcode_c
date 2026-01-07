#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}

const int mod = 1e9 + 7;
long long ans, total;

int dfs(struct TreeNode* root, bool compute)
{
    if (!root)
    {
        return 0;
    }
    int sum = root->val + dfs(root->left, compute) + dfs(root->right, compute);
    if (compute)
    {
        ans = max(ans, (total - sum) * sum);
    }
    return sum;
}

int maxProduct(struct TreeNode* root)
{
    ans = INT_MIN;
    total = dfs(root, false);
    dfs(root, true);
    return ans % mod;
}
