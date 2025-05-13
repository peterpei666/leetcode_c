#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* freqAlphabets(char* s)
{
    int i=0,c=0,t,n;
    n=(int)strlen(s);
    char* ret=(char*)malloc(sizeof(char)*(n+1));
    while(i<n)
    {
        if(i+2<n&&s[i+2]=='#')
        {
            t=(s[i]-'0')*10+s[i+1]-'0'-1;
            ret[c]='a'+t;
            i+=3;
        }
        else
        {
            t=s[i]-'1';
            ret[c]='a'+t;
            i++;
        }
        c++;
    }
    ret[c]='\0';
    return ret;
}
