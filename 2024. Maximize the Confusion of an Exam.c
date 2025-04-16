#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int maxint(int a,int b)
{
    return a>b?a:b;
}

int maxConsecutiveAnswers(char* answerKey, int k)
{
    int i,l,len,count,ret=0;
    len=(int)strlen(answerKey);
    for(i=0,l=0,count=0;i<len;i++)
    {
        if(answerKey[i]=='F')
        {
            count++;
        }
        while(count>k&&l<=i)
        {
            if(answerKey[l]=='F')
            {
                count--;
            }
            l++;
        }
        ret=maxint(ret,i-l+1);
    }
    for(i=0,l=0,count=0;i<len;i++)
    {
        if(answerKey[i]=='T')
        {
            count++;
        }
        while(count>k&&l<=i)
        {
            if(answerKey[l]=='T')
            {
                count--;
            }
            l++;
        }
        ret=maxint(ret,i-l+1);
    }
    return ret;
}

