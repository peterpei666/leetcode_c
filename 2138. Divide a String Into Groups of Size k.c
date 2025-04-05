#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a>b?b:a;
}

char** divideString(char* s, int k, char fill, int* returnSize)
{
    int i,count=0;
    int len=(int)strlen(s);
    int size=len/k;
    int temp;
    if(len%k)
    {
        size++;
    }
    char** ret=(char**)malloc(sizeof(char*)*size);
    for(i=0;i<len;i+=k)
    {
        ret[count]=(char*)malloc(sizeof(char)*(k+1));
        temp=min(k,len-i);
        memcpy(ret[count],s+i,temp);
        if(temp<k)
        {
            memset(ret[count]+temp,fill,k-temp);
        }
        ret[count][k]='\0';
        count++;
    }
    *returnSize=size;
    return ret;
}
