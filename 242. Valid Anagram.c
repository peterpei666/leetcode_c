#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t)
{
    int i,l1,l2;
    int cnt1[26]={0};
    int cnt2[26]={0};
    l1=(int)strlen(s);
    for(i=0;i<l1;i++)
    {
        cnt1[s[i]-'a']++;
    }
    l2=(int)strlen(t);
    for(i=0;i<l2;i++)
    {
        cnt2[t[i]-'a']++;
    }
    return memcmp(cnt1,cnt2,sizeof(int)*26)==0;
}
