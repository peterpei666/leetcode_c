#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int* nums, int n)
{
    int cnt = nums[0] < nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        cnt += nums[i - 1] > nums[i];
    }
    return cnt <= 1;
}
