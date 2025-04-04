#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str,int size)
{
    int i;
    char temp;
    for(i=0;i<size/2;i++)
    {
        temp=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=temp;
    }
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

char* reverseStr(char* s, int k)
{
    int i=0;
    int len=(int)strlen(s);
    int size;
    char* temp=(char*)malloc(sizeof(char)*k);
    while(i<len)
    {
        size=min(k,len-i);
        memcpy(temp,s+i,size);
        reverse(temp,size);
        memcpy(s+i,temp,size);
        i+=2*k;
    }
    free(temp);
    return s;
}
