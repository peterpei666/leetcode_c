#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max_int(int a,int b)
{
    return a>b?a:b;
}

int longest(char* s, int k,int start,int end)
{
    int i,f=1,t,left=0,max=0;
    int list[26]={0};
    if(end-start==0||end-start<k)
    {
        return 0;
    }
    for(i=start;i<end;i++)
    {
        list[s[i]-'a']++;
    }
    for(i=start;i<end;i++)
    {
        if(list[s[i]-'a']<k)
        {
            f=0;
            t=longest(s,k,left,i);
            max=max_int(max,t);
            left=i+1;
        }
    }
    if(f==0)
    {
        t=longest(s,k,left,end);
        max=max_int(max,t);
    }
    if(f)
    {
        return end-start;
    }
    else
    {
        if(max<k)
        {
            max=0;
        }
        return max;
    }
}

int longestSubstring(char* s, int k)
{
    return longest(s,k,0,(int)strlen(s));
}

