#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs,int strsSize)
{
    int minlen=10000,i,j,temp,flag=1,capacity=10;
    char* s=(char*)malloc(capacity*sizeof(char));
    char t;
    for(i=0;i<strsSize;i++)
    {
        temp=(int)strlen(strs[i]);
        if(temp<minlen)
        {
            minlen=temp;
        }
    }
    for(i=0;i<minlen;i++)
    {
        if(i>=capacity-2)
        {
            capacity+=10;
            s=(char*)realloc(s,capacity*sizeof(char));
        }
        t=*(strs[0]+i);
        for(j=0;j<strsSize;j++)
        {
            if(*(strs[j]+i)!=t)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            s[i]=t;
        }
        else
        {
            break;
        }
    }
    s[i]='\0';
    return s;
}
