#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maximumOddBinaryNumber(char* s)
{
    int i,len,count=0;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='1')
        {
            count++;
        }
    }
    memset(s,'0',len);
    memset(s,'1',count-1);
    s[len-1]='1';
    return s;
}
