#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static inline double min(double a, double b)
{
    return a < b ? a : b;
}

double angleClock(int hour, int minutes)
{
    double a = hour * 30 + minutes / 2.0;
    double b = minutes * 6;
    return min(fabs(a - b), 360 - fabs(a - b));
}
