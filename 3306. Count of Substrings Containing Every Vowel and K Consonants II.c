#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cnt[5];

inline bool valid(void)
{
    return cnt[0]&&cnt[1]&&cnt[2]&&cnt[3]&&cnt[4];
}

inline int vowel(char c)
{
    switch(c)
    {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            return -1;
    }
}

long long countOfSubstrings(char* word, int k)
{
    memset(cnt,0,sizeof(cnt));
    int n=(int)strlen(word);
    int next[n];
    for(int i=n-1,temp=n;i>=0;i--)
    {
        next[i]=temp;
        if(vowel(word[i])==-1)
        {
            temp=i;
        }
    }
    int l=0,r=0,con=0;
    long long ans=0;
    while(r<n)
    {
        int pr=vowel(word[r]);
        if(pr==-1)
        {
            con++;
        }
        else
        {
            cnt[pr]++;
        }
        while(con>k)
        {
            int pl=vowel(word[l]);
            if(pl==-1)
            {
                con--;
            }
            else
            {
                cnt[pl]--;
            }
            l++;
        }
        while(con==k&&valid()&&l<n)
        {
            int pl=vowel(word[l]);
            ans+=next[r]-r;
            if(pl==-1)
            {
                con--;
            }
            else
            {
                cnt[pl]--;
            }
            l++;
        }
        r++;
    }
    return ans;
}
