#include <stdio.h>
#include <stdlib.h>

long long dividePlayers(int* skill, int n)
{
    int i;
    int list[1001]={0};
    long long sum=0;
    long long ans=0;
    for(i=0;i<n;i++)
    {
        list[skill[i]]++;
        sum+=skill[i];
    }
    n/=2;
    if(sum%n)
    {
        return -1;
    }
    sum/=n;
    for(i=1;i<=sum/2;i++)
    {
        if(sum-i>1000)
        {
            continue;
        }
        if(sum==2*i)
        {
            if(list[i]%2)
            {
                return -1;
            }
            ans+=(long long)i*i*list[i]/2;
            list[i]=0;
        }
        else
        {
            if(list[(int)(sum-i)]!=list[i])
            {
                return -1;
            }
            ans+=i*(sum-i)*list[i];
            list[i]=0;
            list[sum-i]=0;
        }
    }
    return ans;
}
