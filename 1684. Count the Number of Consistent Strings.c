#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool valid(char* s,bool allow[26])
{
    int i,len;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(allow[s[i]-'a']==false)
        {
            return false;
        }
    }
    return true;
}

int countConsistentStrings(char* allowed, char** words, int wordsSize)
{
    int i,len,count=0;
    bool allow[26];
    memset(allow,false,26);
    len=(int)strlen(allowed);
    for(i=0;i<len;i++)
    {
        allow[allowed[i]-'a']=true;
    }
    for(i=0;i<wordsSize;i++)
    {
        if(valid(words[i],allow))
        {
            count++;
        }
    }
    return count;
}
