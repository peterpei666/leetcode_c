#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumLengthSubstring(char* s)
{
    int i,j;
    int n=(int)strlen(s);
    int cnt[26]={0};
    int ans=0;
    for(i=0,j=0;i<n;i++)
    {
        cnt[s[i]-'a']++;
        while(cnt[s[i]-'a']>2)
        {
            cnt[s[j]-'a']--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}
