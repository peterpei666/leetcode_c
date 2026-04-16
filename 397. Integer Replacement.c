#include <stdio.h>
#include <stdlib.h>

int integerReplacement(int n)
{
    int ans = 0;
    long long cur = n;
    while (cur != 1)
    {
        ans++;
        if (cur & 1)
        {
            if (cur != 3 && (cur & 3) == 3)
            {
                cur++;
            }
            else
            {
                cur--;
            }
        }
        else
        {
            cur >>= 1;
        }
    }
    return ans;
}
