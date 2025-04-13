#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* smallestString(char* s)
{
    int head=-1,tail=-1,i=0,len;
    len=(int)strlen(s);
    while(i<len)
    {
        if(s[i]!='a')
        {
            break;
        }
        i++;
    }
    head=i;
    if(head==len)
    {
        s[len-1]='z';
        return s;
    }
    while(i<len)
    {
        if(s[i]=='a')
        {
            break;
        }
        i++;
    }
    tail=i;
    for(i=head;i<tail;i++)
    {
        s[i]--;
    }
    return s;
}
