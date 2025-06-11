#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumCostSubstring(char* s, char* chars, int* vals, int m)
{
    int i;
    int n=(int)strlen(s);
    int ans=0;
    int prev=0;
    int cur=0;
    int list[26];
    for(i=0;i<26;i++)
    {
        list[i]=i+1;
    }
    for(i=0;i<m;i++)
    {
        list[chars[i]-'a']=vals[i];
    }
    for(i=0;i<n;i++)
    {
        cur+=list[s[i]-'a'];
        ans=max(ans,cur-prev);
        prev=min(prev,cur);
    }
    return ans;
}
