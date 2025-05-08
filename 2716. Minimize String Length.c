#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimizedStringLength(char* s)
{
    int i,count=0,len;
    int find=0;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if((find&(1<<(s[i]-'a')))==0)
        {
            count++;
            find|=1<<(s[i]-'a');
        }
    }
    return count;
}
