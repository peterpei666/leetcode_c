#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subarraysDivByK(int* nums, int n, int k)
{
    int i;
    int cur=0,ans=0;
    int mp[k];
    memset(mp,0,sizeof(mp));
    mp[0]=1;
    for(i=0;i<n;i++)
    {
        cur=((cur+nums[i])%k+k)%k;
        ans+=mp[cur];
        mp[cur]++;
    }
    return ans;
}
