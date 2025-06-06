#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkInclusion(char* s1, char* s2)
{
    int i;
    int l1=(int)strlen(s1);
    int l2=(int)strlen(s2);
    int cnt1[26]={0};
    int cnt2[26]={0};
    if(l2<l1)
    {
        return false;
    }
    for(i=0;i<l1;i++)
    {
        cnt1[s1[i]-'a']++;
        cnt2[s2[i]-'a']++;
    }
    for(i=l1;i<l2;i++)
    {
        if(memcmp(cnt1,cnt2,sizeof(cnt1))==0)
        {
            return true;
        }
        cnt2[s2[i]-'a']++;
        cnt2[s2[i-l1]-'a']--;
    }
    if(memcmp(cnt1,cnt2,sizeof(cnt1))==0)
    {
        return true;
    }
    return false;
}
