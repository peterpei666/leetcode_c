#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getRow(int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    for (int i = 1; i <= n + 1; i++)
    {
        int temp[40];
        temp[0] = 1;
        temp[i - 1] = 1;
        for (int j = 1; j < i - 1; j++)
        {
            temp[j] = ans[j - 1] + ans[j];
        }
        memcpy(ans, temp, sizeof(int) * i);
    }
    return ans;
}
