#include <stdio.h>
#include <stdlib.h>

int min(int a,int b,int c)
{
    int min=a;
    if(b<min)
    {
        min=b;
    }
    if(c<min)
    {
        min=c;
    }
    return min;
}

int nthUglyNumber(int n)
{
    int i2=0,i3=0,i5=0,next,i,temp;
    int next2=2,next3=3,next5=5;
    int* list=(int*)malloc(n*sizeof(int));
    list[0]=1;
    for(i=1;i<n;i++)
    {
        next=min(next2,next3,next5);
        list[i]=next;
        if(next==next2)
        {
            i2++;
            next2=2*list[i2];
        }
        if(next==next3)
        {
            i3++;
            next3=3*list[i3];
        }
        if(next==next5)
        {
            i5++;
            next5=5*list[i5];
        }
    }
    temp=list[n-1];
    free(list);
    return temp;
}
