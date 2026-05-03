#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool rotateString(char* s, char* goal)
{
    int m = (int)strlen(s);
    int n = (int)strlen(goal);
    if (m != n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        bool valid = true;
        for (int k = 0; k < n; k++)
        {
            if (s[(i + k) % n] != goal[k])
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            return true;
        }
    }
    return false;
}
