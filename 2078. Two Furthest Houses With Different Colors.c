#include <stdio.h>
#include <stdlib.h>

int maxDistance(int* colors, int n)
{
    if (colors[0] != colors[n - 1])
    {
        return n - 1;
    }
    int c = colors[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (colors[i] != c || colors[n - 1 - i] != c)
        {
            return n - 1 - i;
        }
    }
    return -1;
}
