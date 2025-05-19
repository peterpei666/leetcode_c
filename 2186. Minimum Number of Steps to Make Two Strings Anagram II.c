#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minSteps(char* s, char* t)
{
    int list[26]={0};
    int i,l,ret=0;
    l=(int)strlen(s);
    for(i=0;i<l;i++)
    {
        list[s[i]-'a']++;
    }
    l=(int)strlen(t);
    for(i=0;i<l;i++)
    {
        list[t[i]-'a']--;
    }
    for(i=0;i<26;i++)
    {
        ret+=abs(list[i]);
    }
    return ret;
}
