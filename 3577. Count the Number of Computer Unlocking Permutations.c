#include <stdio.h>
#include <stdlib.h>

int countPermutations(int* complexity, int n)
{
    long long ans = 1;
    const int mod = 1e9 + 7;
    for (int i = 1; i < n; i++)
    {
        if (complexity[i] <= complexity[0])
        {
            return 0;
        }
        ans = (ans * i) % mod;
    }
    return ans % mod;
}
