#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static inline bool line(int* a, int* b, int* c)
{
    return (b[1] - a[1]) * (c[0] - b[0]) == (c[1] - b[1]) * (b[0] - a[0]);
}

static inline double area(int* a, int* b, int* c)
{
    double l1 = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    double l2 = sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2));
    double l3 = sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2));
    double p = (l1 + l2 + l3) / 2;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}

static inline double max(double a, double b)
{
    return a > b ? a : b;
}

double largestTriangleArea(int** points, int n, int* pointsColSize)
{
    double s = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (!line(points[i], points[j], points[k]))
                {
                    s = max(s, area(points[i], points[j], points[k]));
                }
            }
        }
    }
    return s;
}
