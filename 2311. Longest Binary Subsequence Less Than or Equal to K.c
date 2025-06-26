#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestSubsequence(char* s, int k)
{
    int i,cnt=0,cur=0;
    int n=(int)strlen(s);
    int bit=32-__builtin_clz(k);
    char c;
    for(i=0;i<n;i++)
    {
        c=s[n-1-i];
        if(c=='1')
        {
            if(i<bit&&cur+(1<<i)<=k)
            {
                cur+=(1<<i);
                cnt++;
            }
        }
        else
        {
            cnt++;
        }
    }
    return cnt;
}
