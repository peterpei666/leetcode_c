#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringHash(char* s, int k)
{
    int i,j,m,hash;
    int n=(int)strlen(s);
    char* ret=(char*)malloc(n/k+1);
    ret[n/k]='\0';
    for(i=0,m=0;i<n;i+=k)
    {
        hash=0;
        for(j=0;j<k;j++)
        {
            hash+=s[i+j]-'a';
        }
        hash%=26;
        ret[m]='a'+hash;
        m++;
    }
    return ret;
}
