#include <stdio.h>
#include <stdlib.h>

int findWinningPlayer(int* skills, int n, int k)
{
    int j=0;
    for(int i=1,cur=0;i<n;i++)
    {
        if(skills[i]>skills[j])
        {
            j=i;
            cur=0;
        }
        cur++;
        if(cur==k)
        {
            break;
        }
    }
    return j;
}
