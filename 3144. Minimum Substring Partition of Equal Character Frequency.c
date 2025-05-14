#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

bool valid(int list[26])
{
    int m1=0;
    for(int i=0;i<26;i++)
    {
        if(list[i]==0)
        {
            continue;
        }
        if(m1==0)
        {
            m1=list[i];
        }
        else
        {
            if(m1!=list[i])
            {
                return false;
            }
        }
    }
    return true;
}

int minimumSubstringsInPartition(char* s)
{
    int i,l,r;
    int n=(int)strlen(s);
    int dp[n];
    int list[26];
    for(i=0;i<n;i++)
    {
        dp[i]=i+1;
    }
    for(r=0;r<n;r++)
    {
        memset(list,0,sizeof(list));
        for(l=r;l>=0;l--)
        {
            list[s[l]-'a']++;
            if(valid(list))
            {
                dp[r]=mini(dp[r],l==0?1:dp[l-1]+1);
            }
        }
    }
    return dp[n-1];
}
