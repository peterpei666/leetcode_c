#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxDifference(char* s)
{
    int i;
    int max_odd=INT_MIN;
    int min_even=INT_MAX;
    int list[26]={0};
    int len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        list[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(list[i]==0)
        {
            continue;
        }
        if(list[i]%2)
        {
            max_odd=max(max_odd,list[i]);
        }
        else
        {
            min_even=min(min_even,list[i]);
        }
    }
    return max_odd - min_even;
}
