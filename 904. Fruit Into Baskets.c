#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int totalFruit(int* fruits, int n)
{
    int mp[n];
    int l=0,ans=0,cnt=0;
    memset(mp,0,sizeof(mp));
    for(int i=0;i<n;i++)
    {
        if(mp[fruits[i]]==0)
        {
            cnt++;
        }
        mp[fruits[i]]++;
        while(cnt>2)
        {
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0)
            {
                cnt--;
            }
            l++;
        }
        ans=max(ans,i-l+1);
    }
    return ans;
}
