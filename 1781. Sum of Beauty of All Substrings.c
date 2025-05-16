#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int beauty(int list[26])
{
    int i,m1=0,m2=INT_MAX;
    for(i=0;i<26;i++)
    {
        if(list[i])
        {
            m1=maxi(list[i],m1);
            m2=mini(list[i],m2);
        }
    }
    return m1-m2;
}

int beautySum(char* s)
{
    int i,j,c,ans=0;
    int n=(int)strlen(s);
    int list[26];
    for(i=0;i<n;i++)
    {
        memset(list,0,sizeof(list));
        c=0;
        for(j=i;j<n;j++)
        {
            if(list[s[j]-'a']==0)
            {
                c++;
            }
            list[s[j]-'a']++;
            if(c>=2)
            {
                ans+=beauty(list);
            }
        }
    }
    return ans;
}
