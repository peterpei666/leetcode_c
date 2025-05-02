#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long pickGifts(int* gifts, int giftsSize, int k)
{
    int m=0,mp=-1,i;
    long long sum=0;
    while(k)
    {
        m=0;
        mp=-1;
        for(i=0;i<giftsSize;i++)
        {
            if(gifts[i]>m)
            {
                m=gifts[i];
                mp=i;
            }
        }
        gifts[mp]=(int)sqrt(m);
        k--;
    }
    for(i=0;i<giftsSize;i++)
    {
        sum+=(long long)gifts[i];
    }
    return sum;
}
