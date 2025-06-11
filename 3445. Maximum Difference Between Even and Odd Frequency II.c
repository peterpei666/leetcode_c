#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline int get_status(int a,int b)
{
    return ((a&1)<<1)|(b&1);
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxDifference(char* s, int k)
{
    int cnt_a,cnt_b;
    int prev_a,prev_b;
    int ans=INT_MIN;
    int n=(int)strlen(s);
    int l,r;
    int left,right;
    int best[4];
    char a,b;
    for(char a='0';a<='4';a++)
    {
        for(char b='0';b<='4';b++)
        {
            if(a==b)
            {
                continue;
            }
            cnt_a=0;
            cnt_b=0;
            prev_a=0;
            prev_b=0;
            best[0]=INT_MAX;
            best[1]=INT_MAX;
            best[2]=INT_MAX;
            best[3]=INT_MAX;
            l=-1;
            for(r=0;r<n;r++)
            {
                if(s[r]==a)
                {
                    cnt_a++;
                }
                if(s[r]==b)
                {
                    cnt_b++;
                }
                while(r-l>=k&&cnt_b-prev_b>=2)
                {
                    left=get_status(prev_a,prev_b);
                    best[left]=min(best[left],prev_a-prev_b);
                    l++;
                    if(s[l]==a)
                    {
                        prev_a++;
                    }
                    if(s[l]==b)
                    {
                        prev_b++;
                    }
                }
                right=get_status(cnt_a,cnt_b);
                if(best[right^0b10]!=INT_MAX)
                {
                    ans=max(ans,cnt_a-cnt_b-best[right^0b10]);
                }
            }
        }
    }
    return ans;
}
