#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumSwap(char* s1, char* s2)
{
    int i;
    int m,n;
    int cnt[2]={0};
    m=(int)strlen(s1);
    n=(int)strlen(s2);
    if(m!=n)
    {
        return -1;
    }
    for(i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            cnt[s1[i]-'x']++;
        }
    }
    if(cnt[0]%2!=cnt[1]%2)
    {
        return -1;
    }
    return (cnt[0]+1)/2+(cnt[1]+1)/2;
}
