#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maximumSubsequenceCount(char* text, char* pattern)
{
    int n=(int)strlen(text);
    int i;
    long long cnt1=1,cnt2=1;
    long long res1=0,res2=0;
    for(i=0;i<n;i++)
    {
        if(text[i]==pattern[1])
        {
            res1+=cnt1;
        }
        if(text[n-1-i]==pattern[0])
        {
            res2+=cnt2;
        }
        if(text[i]==pattern[0])
        {
            cnt1++;
        }
        if(text[n-1-i]==pattern[1])
        {
            cnt2++;
        }
    }
    return maxi(res1,res2);
}
