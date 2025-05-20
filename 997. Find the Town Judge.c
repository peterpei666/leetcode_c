#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize)
{
    int i;
    int ee[n+1];
    int er[n+1];
    memset(ee,0,sizeof(ee));
    memset(er,0,sizeof(er));
    for(i=0;i<trustSize;i++)
    {
        ee[trust[i][1]]++;
        er[trust[i][0]]++;
    }
    for(i=1;i<=n;i++)
    {
        if(ee[i]==n-1&&er[i]==0)
        {
            return i;
        }
    }
    return -1;
}
