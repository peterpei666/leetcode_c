#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

static inline bool valid(int mps[128],int mpt[128])
{
    for(int i=0;i<128;i++)
    {
        if(mps[i]<mpt[i])
        {
            return false;
        }
    }
    return true;
}

char* minWindow(char* s, char* t)
{
    int m=(int)strlen(s);
    int n=(int)strlen(t);
    int mps[128]={0};
    int mpt[128]={0};
    for(int i=0;i<n;i++)
    {
        mpt[t[i]]++;
    }
    int l=0,r=0;
    int minLen=INT_MAX,start=0;
    while(r<m)
    {
        mps[s[r]]++;
        r++;
        while(valid(mps,mpt))
        {
            if(r-l<minLen)
            {
                minLen=r-l;
                start=l;
            }
            mps[s[l]]--;
            l++;
        }
    }
    char* ans;
    if(minLen==INT_MAX)
    {
        ans=(char*)malloc(1);
        ans[0]='\0';
    }
    else
    {
        ans=(char*)malloc(minLen+1);
        ans[minLen]='\0';
        memcpy(ans,s+start,minLen);
    }
    return ans;
}
