#include <stdio.h>
#include <stdlib.h>

int P(int n, int k)
{
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= (n - i);
    }
    return ans;
}

int countNumbersWithUniqueDigits(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans += 9 * P(9, i - 1);
    }
    return ans;
}
