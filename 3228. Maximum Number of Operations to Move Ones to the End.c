#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxOperations(char* s)
{
    int i,count=0,ret=0,len;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='1')
        {
            count++;
        }
        if(s[i]=='0'&&(i+1>=len||s[i+1]=='1'))
        {
            ret+=count;
        }
    }
    return ret;
}
