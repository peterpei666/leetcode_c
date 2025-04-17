#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shortestPalindrome(char* s)
{
    int i,max=1,j,p=0;
    int len=(int)strlen(s);
    char* temp=(char*)malloc(sizeof(char)*(len+1));
    temp[len]='\0';
    for(i=0;i<len;i++)
    {
        temp[len-i-1]=s[i];
    }
    for(i=0;i<len;i++)
    {
        if(memcmp(temp+i,s,len-i)==0)
        {
            break;
        }
    }
    char* ret=(char*)malloc(sizeof(char)*(i+len+1));
    memcpy(ret,temp,i);
    strcpy(ret+i,s);
    free(temp);
    return ret;
}
