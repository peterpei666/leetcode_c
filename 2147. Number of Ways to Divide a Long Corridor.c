#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numberOfWays(char* corridor)
{
    char* t = corridor;
    long long ans = 1;
    bool valid = false;
    const int mod = 1e9 + 7;
    int cnt = 0, temp = 0;
    while (*t != '\0')
    {
        if (*t == 'S')
        {
            if (cnt == 2)
            {
                ans = ans * temp % mod;
                temp = 0;
                cnt = 0;
            }
            else if (cnt == 1)
            {
                temp = 1;
                valid = true;
            }
            cnt++;
        }
        else
        {
            if (cnt == 2)
            {
                temp++;
            }
        }
        t++;
    }
    if (cnt == 1)
    {
        valid = false;
    }
    if (valid)
    {
        return ans % mod;
    }
    return 0;
}
