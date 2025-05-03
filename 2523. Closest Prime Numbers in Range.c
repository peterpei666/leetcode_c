#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int prime(int x)
{
    int i,max;
    if(x==1)
    {
        return 0;
    }
    if(x<100)
    {
        for(i=0;i<25;i++)
        {
            if(x==p[i])
            {
                return 1;
            }
        }
    }
    for(i=0;i<25;i++)
    {
        if(x%p[i]==0)
        {
            return 0;
        }
    }
    max=sqrt(x);
    for(i=3;i<=max;i+=2)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int* closestPrimes(int left, int right, int* returnSize)
{
    int i,j,min,p=0;
    int* current=(int*)malloc(sizeof(int)*2);
    int temp[2]={0};
    min=10000000;
    for(i=left;i<=right;i++)
    {
        if(prime(i))
        {
            if(p==0)
            {
                temp[p]=i;
                p++;
            }
            else
            {
                temp[1]=i;
                if(temp[1]-temp[0]<min)
                {
                    min=temp[1]-temp[0];
                    current[1]=temp[1];
                    current[0]=temp[0];
                }
                temp[0]=i;
            }
        }
        if(min==1||min==2)
        {
            break;
        }
    }
    *returnSize=2;
    if(min==10000000)
    {
        current[0]=-1;
        current[1]=-1;
    }
    return current;
}
