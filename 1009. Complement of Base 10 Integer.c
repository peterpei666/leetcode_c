#include <stdio.h>
#include <stdlib.h>

int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; (1 << i) <= n; i++)
    {
        if ((n & (1 << i)) == 0)
        {
            ans |= 1 << i;
        }
    }
    return ans;
}
