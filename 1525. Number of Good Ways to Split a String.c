#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numSplits(char* s)
{
    int c1=0,c2=0,ret=0,i,len;
    int list1[26]={0},list2[26]={0};
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(list2[s[i]-'a']==0)
        {
            c2++;
        }
        list2[s[i]-'a']++;
    }
    for(i=0;i<len-1;i++)
    {
        if(list1[s[i]-'a']==0)
        {
            c1++;
        }
        list1[s[i]-'a']++;
        list2[s[i]-'a']--;
        if(list2[s[i]-'a']==0)
        {
            c2--;
        }
        if(c1==c2)
        {
            ret++;
        }
    }
    return ret;
}
