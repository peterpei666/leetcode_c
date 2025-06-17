#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool winnerOfGame(char* colors)
{
    int i;
    int cntA=0,cntB=0;
    int tempA=0,tempB=0;
    int n=(int)strlen(colors);
    for(i=0;i<n;i++)
    {
        if(colors[i]=='A')
        {
            if(tempB>2)
            {
                cntB+=tempB-2;
            }
            tempB=0;
            tempA++;
        }
        else
        {
            if(tempA>2)
            {
                cntA+=tempA-2;
            }
            tempA=0;
            tempB++;
        }
    }
    if(tempA>2)
    {
        cntA+=tempA-2;
    }
    if(tempB>2)
    {
        cntB+=tempB-2;
    }
    return cntA>cntB;
}
