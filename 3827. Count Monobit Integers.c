#include <stdio.h>
#include <stdlib.h>

int countMonobit(int n)
{
    int ans = 0;
    for (int i = 0; i < 20; i++)
    {
        if (n >= (1 << i) - 1)
        {
            ans++;
        }
    }
    return ans;
}
