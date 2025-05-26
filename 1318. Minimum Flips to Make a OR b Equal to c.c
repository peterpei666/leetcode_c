#include <stdio.h>
#include <stdlib.h>

int minFlips(int a, int b, int c)
{
    int count=0;
    int temp;
    while(c||(a|b))
    {
        temp=a|b;
        if((c&1)==1&&(temp&1)==0)
        {
            count++;
        }
        else if((c&1)==0&&(temp&1)==1)
        {
            count+=(a&1)+(b&1);
        }
        a>>=1;
        b>>=1;
        c>>=1;
    }
    return count;
}
