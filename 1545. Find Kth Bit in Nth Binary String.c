#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

char findKthBit(int n, int k)
{
    int i,len=1;
    char ret;
    char temp[]="1";
    char* s=(char*)malloc(2*k);
    char* t;
    s[0]='0';
    s[1]='\0';
    k--;
    while(len<=k)
    {
        t=strdup(s);
        for(i=0;i<len;i++)
        {
            t[i]=t[i]=='0'?'1':'0';
        }
        for(i=0;i<len/2;i++)
        {
            swap(&t[i],&t[len-1-i]);
        }
        s=strcat(s,temp);
        s=strcat(s,t);
        free(t);
        len=2*len+1;
    }
    ret=s[k];
    free(s);
    return ret;
}
