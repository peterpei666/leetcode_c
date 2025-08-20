#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSelfCrossing(int* d, int n)
{
    if(n<4)
    {
        return false;
    }
    int distance[n+1];
    distance[0]=0;
    memcpy(distance+1,d,sizeof(int)*n);
    n++;
    for(int i=4;i<n;i++)
    {
        if(distance[i-2]<=distance[i]&&distance[i-3]>=distance[i-1])
        {
            return true;
        }
        if(i>=5)
        {
            if(distance[i-2]>=distance[i-4]&&distance[i-2]<=distance[i-4]+distance[i]&&distance[i-3]>=distance[i-1]&&distance[i-3]<=distance[i-1]+distance[i-5])
            {
                return true;
            }
        }
    }
    return false;
}
