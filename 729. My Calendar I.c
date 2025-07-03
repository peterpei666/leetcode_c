#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char kthCharacter(long long k, int* operations, int operationsSize)
{
    int cnt=0,temp;
    while(k!=1)
    {
        temp=log2(k);
        if((1LL<<temp)==k)
        {
            temp--;
        }
        k-=1LL<<temp;
        if(operations[temp])
        {
            cnt++;
        }
    }
    return 'a'+cnt%26;
}
