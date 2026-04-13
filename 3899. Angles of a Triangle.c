#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* p1, const void* p2)
{
    return *(double*)p1 > *(double*)p2 ? 1 : -1;
}

double* internalAngles(int* sides, int sidesSize, int* returnSize)
{
    double* ans = (double*)malloc(sizeof(double) * 3);
    int a = sides[0], b = sides[1], c = sides[2];
    if (!(a + b > c && a + c > b && b + c > a))
    {
        *returnSize = 0;
        return ans;
    }
    const double pi = 3.1415926535897;
    double a1 = acos((a * a + b * b - c * c) * 1.0 / (2 * a * b)) / pi * 180;
    double a2 = acos((c * c + b * b - a * a) * 1.0 / (2 * c * b)) / pi * 180;
    double a3 = acos((a * a + c * c - b * b) * 1.0 / (2 * a * c)) / pi * 180;
    ans[0] = a1;
    ans[1] = a2;
    ans[2] = a3;
    qsort(ans, 3, sizeof(double), cmp);
    *returnSize = 3;
    return ans;
}
