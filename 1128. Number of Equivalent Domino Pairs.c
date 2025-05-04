#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
    int i,m1,m2,count=0;
    int mp[100]={0};
    for(i=0;i<dominoesSize;i++)
    {
        m1=maxi(dominoes[i][0],dominoes[i][1]);
        m2=mini(dominoes[i][0],dominoes[i][1]);
        mp[m2*10+m1]++;
    }
    for(i=0;i<100;i++)
    {
        if(mp[i]>1)
        {
            count+=mp[i]*(mp[i]-1)/2;
        }
    }
    return count;
}
