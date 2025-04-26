#include <stdio.h>
#include <stdlib.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

inline long long mini(long long a,long long b)
{
    return a>b?b:a;
}

int numberOfArrays(int* differences, int differencesSize, int lower, int upper)
{
    int i;
    long long temp=0,m1=0,m2=0;
    for(i=0;i<differencesSize;i++)
    {
        temp+=(long long)differences[i];
        m1=maxi(m1,temp);
        m2=mini(m2,temp);
    }
    if(upper-m1<lower-m2)
    {
        return 0;
    }
    else
    {
        return (int)(upper-m1-lower+m2+1);
    }
}
