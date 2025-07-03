#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int findSubstringInWraproundString(char* s)
{
    int i,cur=1,n,ans=0;
    int list[26]={0};
    n=(int)strlen(s);
    list[s[0]-'a']=1;
    for(i=1;i<n;i++)
    {
        if((s[i]-s[i-1]+26)%26==1)
        {
            cur++;
        }
        else
        {
            cur=1;
        }
        list[s[i]-'a']=max(list[s[i]-'a'],cur);
    }
    for(i=0;i<26;i++)
    {
        ans+=list[i];
    }
    return ans;
}
