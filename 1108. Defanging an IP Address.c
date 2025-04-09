#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address)
{
    int i,j,len;
    len=(int)strlen(address);
    char* ret=(char*)malloc(sizeof(char)*(len+7));
    for(i=0,j=0;i<len;i++)
    {
        if(address[i]=='.')
        {
            ret[j]='[';
            ret[j+1]='.';
            ret[j+2]=']';
            j+=3;
        }
        else
        {
            ret[j]=address[i];
            j++;
        }
    }
    ret[j]='\0';
    return ret;
}
