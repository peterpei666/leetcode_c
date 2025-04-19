#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefixCount(char** words, int wordsSize, char* pref)
{
    int count=0,len,i;
    len=(int)strlen(pref);
    for(i=0;i<wordsSize;i++)
    {
        if(strncmp(words[i],pref,len)==0)
        {
            count++;
        }
    }
    return count;
}

