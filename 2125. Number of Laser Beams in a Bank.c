#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfBeams(char** bank, int bankSize)
{
    int ans=0,prev=0,cur,len,i,j;
    len=(int)strlen(bank[0]);
    for(i=0;i<bankSize;i++)
    {
        cur=0;
        for(j=0;j<len;j++)
        {
            cur+=bank[i][j]-'0';
        }
        if(cur)
        {
            ans+=prev*cur;
            prev=cur;
        }
    }
    return ans;
}
