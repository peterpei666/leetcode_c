#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k)
{
    char* s=(char*)malloc(n+1);
    s[n]='\0';
    memset(s,'0',n);
    k--;
    short used=0;
    int factorial[9];
    factorial[0]=1;
    for(int i=1;i<9;i++)
    {
        factorial[i]=factorial[i-1]*i;
    }
    for(int i=0;i<n;i++)
    {
        int m=k/factorial[n-i-1];
        k%=factorial[n-i-1];
        for(int j=1;j<=n;j++)
        {
            if(used&(1<<j))
            {
                continue;
            }
            if(m==0)
            {
                used|=1<<j;
                s[i]+=j;
                break;
            }
            else
            {
                m--;
            }
        }
    }
    return s;
}
