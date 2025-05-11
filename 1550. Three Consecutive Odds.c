#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int c=0,i;
    for(i=0;i<arrSize;i++)
    {
        if(arr[i]&1)
        {
            c++;
            if(c==3)
            {
                return true;
            }
        }
        else
        {
            c=0;
        }
    }
    return false;
}
