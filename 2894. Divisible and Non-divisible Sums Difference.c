#include <stdio.h>
#include <stdlib.h>

int differenceOfSums(int n, int m)
{
    int i;
    int num1=0,num2=0;
    for(i=1;i<=n;i++)
    {
        if(i%m)
        {
            num1+=i;
        }
        else
        {
            num2+=i;
        }
    }
    return num1-num2;
}
