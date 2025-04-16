#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char findTheDifference(char* s, char* t)
{
    int i;
    int len=(int)strlen(s);
    int count[26]={0};
    char ret='\0';
    for(i=0;i<len;i++)
    {
        count[s[i]-'a']++;
    }
    for(i=0;i<=len;i++)
    {
        count[t[i]-'a']--;
        if(count[t[i]-'a']==-1)
        {
            ret=t[i];
            break;
        }
    }
    return ret;
}
