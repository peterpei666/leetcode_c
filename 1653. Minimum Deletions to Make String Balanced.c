#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumDeletions(char* s)
{
    int i,n,ans=0;
    int l=0,r=0;
    n=(int)strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            r++;
        }
    }
    ans=min(n-r,r);
    for(i=0;i<n;i++)
    {
        if(s[i]=='b')
        {
            l++;
        }
        else
        {
            r--;
        }
        ans=min(ans,l+r);
    }
    return ans;
}
