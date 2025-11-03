#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minCost(char* colors, int* neededTime, int n)
{
    int ans = 0;
    for (int i = 0; i < n;)
    {
        char c = colors[i];
        int sum = neededTime[i], t = neededTime[i];
        i++;
        while (i < n && colors[i] == c)
        {
            sum += neededTime[i];
            t = max(t, neededTime[i]);
            i++;
        }
        ans += sum - t;
    }
    return ans;
}
