#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partitionString(char* s)
{
    int i,n,cnt,found;
    n=(int)strlen(s);
    cnt=1;
    found=0;
    for(i=0;i<n;i++)
    {
        if(found&(1<<(s[i]-'a')))
        {
            found=0;
            cnt++;
        }
        found|=1<<(s[i]-'a');
    }
    return cnt;
}
