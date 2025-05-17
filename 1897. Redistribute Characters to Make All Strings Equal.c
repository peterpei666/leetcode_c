#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool makeEqual(char** words, int w)
{
    int i,j,l;
    int list[26]={0};
    for(i=0;i<w;i++)
    {
        l=(int)strlen(words[i]);
        for(j=0;j<l;j++)
        {
            list[words[i][j]-'a']++;
        }
    }
    for(i=0;i<26;i++)
    {
        if(list[i]%w)
        {
            return false;
        }
    }
    return true;
}
