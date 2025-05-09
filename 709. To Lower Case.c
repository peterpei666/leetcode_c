#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLowerCase(char* s)
{
    int i,len;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]<='Z'&&s[i]>='A')
        {
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}
