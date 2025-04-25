#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* s, int k)
{
    int mask=0,len;
    len=(int)strlen(s);
    if(len<k)
    {
        return false;
    }
    while(len)
    {
        mask^=(1<<(s[len-1]-'a'));
        len--;
    }
    while(mask)
    {
        if(mask&1)
        {
            k--;
        }
        mask>>=1;
    }
    if(k<0)
    {
        return false;
    }
    return true;
}

