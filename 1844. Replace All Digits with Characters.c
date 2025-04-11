#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceDigits(char* s)
{
    int i,len,t;
    len=(int)strlen(s);
    for(i=0;i<len;i+=2)
    {
        if(i+1<len)
        {
            t=s[i+1]-'0';
            s[i+1]=t+s[i];
        }
    }
    return s;
}
