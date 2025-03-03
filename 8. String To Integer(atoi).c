#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* s)
{
    int len=(int)strlen(s),i=0,f=0,j=0;
    long long ans=0;
    int ret;
    while(i<len&&*(s+i)==' ')
    {
        i++;
    }
    if(*(s+i)=='-')
    {
        f=1;
        i++;
    }
    else if(*(s+i)=='+')
    {
        f=0;
        i++;
    }
    while(*(s+i)=='0')
    {
        i++;
    }
    while(*(s+i)<='9'&&*(s+i)>='0'&&i<len&&j<11)
    {
        ans*=10;
        ans+=*(s+i)-'0';
        i++;
        j++;
    }
    if(f)
    {
        ans*=-1;
    }
    if(ans>2147483647)
    {
        ret=2147483647;
    }
    else if(ans<-2147483648)
    {
        ret=-2147483648;
    }
    else
    {
        ret=(int)ans;
    }
    return ret;
}
