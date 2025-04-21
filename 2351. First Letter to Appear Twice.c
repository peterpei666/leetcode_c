#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char repeatedCharacter(char* s)
{
    int i;
    int len=(int)strlen(s);
    bool list[26];
    memset(list,false,26);
    for(i=0;i<len;i++)
    {
        if(list[s[i]-'a'])
        {
            return s[i];
        }
        else
        {
            list[s[i]-'a']=true;
        }
    }
    return '\0';
}
