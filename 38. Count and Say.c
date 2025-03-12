#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n)
{
    if(n==1)
    {
        return strdup("1");
    }
    if(n==2)
    {
        return strdup("11");
    }
    char* s=strdup("11");
    int i,j,k,count,len;
    
    for(i=3;i<=n;i++)
    {
        len=(int)strlen(s);
        char* t=(char*)malloc(sizeof(char)*(2*len+1));
        s[len]='A';
        count=1;
        k=0;
        for(j=1;j<=len;j++)
        {
            if(s[j]!=s[j-1])
            {
                k+=sprintf(t+k,"%d%c",count,s[j-1]);
                count=1;
            }
            else
            {
                count++;
            }
        }
        free(s);
        s=t;
    }
    return s;
}
