#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* closestDivisors(int num, int* returnSize)
{
    int i,dif=num;
    int* ret=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    ret[0]=1;
    ret[1]=num+1;
    num++;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0&&abs(i-num/i)<dif)
        {
            dif=abs(i-num/i);
            ret[0]=i;
            ret[1]=num/i;
            if(dif==0)
            {
                return ret;
            }
        }
    }
    num++;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0&&abs(i-num/i)<dif)
        {
            dif=abs(i-num/i);
            ret[0]=i;
            ret[1]=num/i;
            if(dif==0)
            {
                return ret;
            }
        }
    }
    return ret;
}
