#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maxValue(char* n, int x)
{
    int i;
    char c=x+'0';
    int l=(int)strlen(n);
    char* ret=(char*)malloc(l+2);
    if(n[0]=='-')
    {
        i=1;
        while(i<l&&n[i]<=c)
        {
            i++;
        }
    }
    else
    {
        i=0;
        while(i<l&&n[i]>=c)
        {
            i++;
        }
    }
    memcpy(ret,n,i);
    ret[i]=c;
    strcpy(ret+i+1,n+i);
    return ret;
}
