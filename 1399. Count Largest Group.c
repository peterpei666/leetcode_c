#include <stdio.h>
#include <stdlib.h>

int digit(int x)
{
    int c=0;
    while(x)
    {
        c+=x%10;
        x/=10;
    }
    return c;
}

int countLargestGroup(int n)
{
    int i,max=0,c=0;
    short count[36]={0};
    for(int i=1;i<=n;i++)
    {
        int m=digit(i);
        count[m-1]++;
    }
    for(i=0;i<36;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            c=1;
        }
        else if(count[i]==max)
        {
            c++;
        }
    }
    return c;
}
