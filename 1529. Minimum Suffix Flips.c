#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minFlips(char* target)
{
    int i,n,cnt=0;
    n=(int)strlen(target);
    for(i=0;i<n;i++)
    {
        if((target[i]-'0')^(cnt&1))
        {
            cnt++;
        }
    }
    return cnt;
}
