#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool palindrome(long long x,int k)
{
    int i,j;
    int list[100];
    int len=-1;
    while(x)
    {
        len++;
        list[len]=x%k;
        x/=k;
    }
    for(i=0,j=len;i<j;i++,j--)
    {
        if(list[i]!=list[j])
        {
            return false;
        }
    }
    return true;
}

long long kMirror(int k, int n)
{
    int left=1,right,op,i,x,cnt=0;
    long long ans=0,combine;
    while(cnt<n)
    {
        right=left*10;
        for(op=0;op<2;op++)
        {
            for(i=left;i<right&&cnt<n;i++)
            {
                combine=i;
                x=op?i:i/10;
                while(x)
                {
                    combine=combine*10+x%10;
                    x/=10;
                }
                if(palindrome(combine,k))
                {
                    cnt++;
                    ans+=combine;
                }
            }
        }
        left=right;
    }
    return ans;
}
