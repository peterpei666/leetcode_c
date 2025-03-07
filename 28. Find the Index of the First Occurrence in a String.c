#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    int len1=(int)strlen(haystack);
    int len2=(int)strlen(needle);
    int i,j,k,f;
    if(len2>len1)
    {
        return -1;
    }
    for(i=0;i<=len1-len2;i++)
    {
        f=1;
        if(*needle!=haystack[i])
        {
            continue;
        }
        for(j=1;j<len2;j++)
        {
            if(needle[j]!=haystack[i+j])
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            return i;
        }
    }
    return -1;
}
