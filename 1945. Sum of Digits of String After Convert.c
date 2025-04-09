#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int transform(char* s,int k)
{
    int i,len;
    len=(int)strlen(s);
    if(k==0||len==1)
    {
        int m=0;
        for(i=0;i<len;i++)
        {
            m*=10;
            m+=s[i]-'0';
        }
        free(s);
        return m;
    }
    else
    {
        int m=0;
        for(i=0;i<len;i++)
        {
            m+=s[i]-'0';
        }
        free(s);
        char* t=(char*)malloc(sizeof(char)*6);
        sprintf(t,"%d",m);
        return transform(t,k-1);
    }
}

int getLucky(char* s, int k)
{
    int i,j,t,len;
    len=(int)strlen(s);
    char* str=(char*)malloc(sizeof(char)*201);
    for(i=0,j=0;i<len;i++)
    {
        t=s[i]-'a'+1;
        if(t>=10)
        {
            str[j]='0'+t/10;
            str[j+1]='0'+t%10;
            j+=2;
        }
        else
        {
            str[j]='0'+t;
            j++;
        }
    }
    str[j]='\0';
    return transform(str,k);
}
