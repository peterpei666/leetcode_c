#include <stdio.h>
#include <stdlib.h>

int countDigits(int num)
{
    int temp=num,cnt=0;
    while(temp)
    {
        if(num%(temp%10)==0)
        {
            cnt++;
        }
        temp/=10;
    }
    return cnt;
}
