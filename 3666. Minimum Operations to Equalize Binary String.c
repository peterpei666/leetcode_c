#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minOperations(char* s, int k)
{
    int n = (int)strlen(s);
    int n0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            n0++;
        }
    }
    if (n0 == 0)
    {
        return 0;
    }
    int n1 = n - n0;
    for (long long i = 1; i <= n; i++)
    {
        long long p = i * k;
        if ((p - n0) % 2)
        {
            continue;
        }
        if (i % 2)
        {
            if (p >= n0 && p <= n0 * i + n1 * (i - 1))
            {
                return (int)i;
            }
        }
        else
        {
            if (p >= n0 && p <= n0 * (i - 1) + n1 * i)
            {
                return (int)i;
            }
        }
    }
    return -1;
}
