#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int n, int* cost, int costSize)
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        r += gas[i] - cost[i];
    }
    if (r < 0)
    {
        return -1;
    }
    int ans = 0;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        r += gas[i] - cost[i];
        if (r < 0)
        {
            ans = i + 1;
            r = 0;
        }
    }
    return ans;
}
