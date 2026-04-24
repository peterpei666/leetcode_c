#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int furthestDistanceFromOrigin(char* moves)
{
    int n = (int)strlen(moves);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l += moves[i] == 'L';
        r += moves[i] == 'R';
    }
    return abs(l - r) + (n - l - r);
}
