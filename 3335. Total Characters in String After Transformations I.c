#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthAfterTransformations(char* s, int t)
{
    int len=(int)strlen(s);
    int i;
    long long temp,sum=0;
    long long list[26]={0};
    long long newlist[26]={0};
    const int MOD=1e9+7;
    for(i=0;i<len;i++)
    {
        list[s[i]-'a']++;
    }
    while(t)
    {
        temp=list[25];
        for(i=25;i>=1;i--)
        {
            list[i]=list[i-1];
        }
        list[0]=temp;
        list[1]+=temp;
        list[1]%=MOD;
        t--;
    }
    for(i=0;i<26;i++)
    {
        sum+=list[i];
    }
    return sum%MOD;
}
