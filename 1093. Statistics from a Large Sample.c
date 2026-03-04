#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline double min(double a, double b)
{
    return a < b ? a : b;
}

double* sampleStats(int* count, int countSize, int* returnSize)
{
    double ans[5] = {255, 0, 0, 0, 0};
    int total = 0;
    for (int i = 0; i < 256; i++)
    {
        total += count[i];
    }
    int m1 = (total + 1) / 2;
    int m2 = (total + 2) / 2;
    for (int i = 0, cnt = 0; i < 256; cnt += count[i], i++)
    {
        if (count[i])
        {
            ans[0] = min((int)ans[0], i);
            ans[1] = i;
        }
        ans[2] += i * 1.0 * count[i] / total;
        if (cnt < m1 && cnt + count[i] >= m1)
        {
            ans[3] += i * 0.5;
        }
        if (cnt < m2 && cnt + count[i] >= m2)
        {
            ans[3] += i * 0.5;
        }
        ans[4] = count[i] > count[(int)ans[4]] ? i : ans[4];
    }
    double* ret = (double*)malloc(sizeof(double) * 5);
    memcpy(ret, ans, sizeof(ans));
    *returnSize = 5;
    return ret;
}
