#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN -32768

unsigned char mp[375];

inline int test(int x)
{
    return mp[x>>3]&(1<<(x&7))?1:0;
}

inline void set(int x)
{
    mp[x>>3]|=(1<<(x&7));
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxRemovals(char* source, char* pattern, int* targetIndices, int targetIndicesSize)
{
    int i,j,d,len1,len2;
    short dp[3001];
    len1=(int)strlen(source);
    len2=(int)strlen(pattern);
    memset(mp,0,375);
    for(i=0;i<len2;i++)
    {
        dp[i]=MIN;
    }
    dp[len2]=0;
    for(i=0;i<targetIndicesSize;i++)
    {
        set(targetIndices[i]);
    }
    for(i=len1-1;i>=0;i--)
    {
        d=test(i);
        for(j=0;j<=len2;j++)
        {
            dp[j]+=d;
            if(j<len2&&source[i]==pattern[j])
            {
                dp[j]=maxi(dp[j],dp[j+1]);
            }
        }
    }
    return dp[0];
}
