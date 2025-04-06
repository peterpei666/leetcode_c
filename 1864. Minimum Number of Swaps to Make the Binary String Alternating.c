#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a,int b)
{
    return a>b?b:a;
}

int count(char* s,char head)
{
    int wrong=0,i;
    int len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!=head)
        {
            wrong++;
        }
        if(head=='0')
        {
            head='1';
        }
        else
        {
            head='0';
        }
    }
    return wrong/2;
}

int minSwaps(char* s)
{
    int count0=0,count1=0;
    int len=(int)strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }
    if(abs(count1-count0)>1)
    {
        return -1;
    }
    if(count0>count1)
    {
        return count(s,'0');
    }
    else if(count0<count1)
    {
        return count(s,'1');
    }
    else
    {
        return min(count(s,'0'),count(s,'1'));
    }
}
