#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int n)
{
    int i = 0;
    bool ans = true;
    while (i < n)
    {
        if (bits[i])
        {
            i += 2;
            ans = false;
        }
        else
        {
            i++;
            ans = true;
        }
    }
    return ans;
}
