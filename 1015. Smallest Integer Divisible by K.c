#include <stdio.h>
#include <stdlib.h>

int smallestRepunitDivByK(int k)
{
    if (k % 2 == 0)
    {
        return -1;
    }
    int temp = 1 % k, ans = 1;
    for (; ans <= k && temp; ans++)
    {
        temp = (temp * 10 + 1) % k;
    }
    return ans == k + 1 ? -1 : ans;
}
