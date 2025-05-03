#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize)
{
    int ret=INT_MAX,i,p;
    int temp1,temp2;
    for(i=1;i<=6;i++)
    {
        temp1=0;
        temp2=0;
        for(p=0;p<topsSize;p++)
        {
            if(tops[p]!=i&&bottoms[p]==i)
            {
                temp1++;
            }
            if(tops[p]==i&&bottoms[p]!=i)
            {
                temp2++;
            }
            if(tops[p]!=i&&bottoms[p]!=i)
            {
                break;
            }
        }
        if(p==topsSize)
        {
            ret=mini(ret,mini(temp1,temp2));
        }
    }
    if(ret==INT_MAX)
    {
        return -1;
    }
    return ret;
}
