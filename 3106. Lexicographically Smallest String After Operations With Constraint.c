#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

char* getSmallestString(char* s, int k)
{
    if(k==0)
    {
        return s;
    }
    int grid[26][26];
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            grid[i][j]=min(abs(i-j),min(abs(i-j+26),abs(i-j-26)));
        }
    }
    int n=(int)strlen(s);
    for(int i=0;i<n;i++)
    {
        int origin=s[i]-'a';
        for(int j=0;j<origin;j++)
        {
            if(grid[origin][j]<=k)
            {
                k-=grid[origin][j];
                s[i]='a'+j;
                break;
            }
        }
    }
    return s;
}
