#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hammingWeight(int n)
{
    int count=0;
    while(n)
    {
        count+=(n&1);
        n>>=1;
    }
    return count;
}
