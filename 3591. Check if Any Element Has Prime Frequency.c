#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline bool prime(int x)
{
    if(x==2||x==3||x==5||x==7||x==11||x==13||x==17||x==19||x==23||x==29||x==31||x==37||x==41||x==43||x==47||x==53||x==59||x==61||x==67||x==71||x==73||x==79||x==83||x==89||x==97)
    {
        return true;
    }
    return false;
}

bool checkPrimeFrequency(int* nums, int n)
{
    int i;
    int list[101]={0};
    for(i=0;i<n;i++)
    {
        list[nums[i]]++;
    }
    for(i=0;i<101;i++)
    {
        if(list[i]==0)
        {
            continue;
        }
        if(prime(list[i]))
        {
            return true;
        }
    }
    return false;
}
