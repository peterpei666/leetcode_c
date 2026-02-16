#include <stdio.h>
#include <stdlib.h>

static inline int reverseBits(int n)
{
    int ans = 0;
    for (int i = 31; n; i--, n >>= 1) ans |= (n & 1) << i;
    return ans;
}
