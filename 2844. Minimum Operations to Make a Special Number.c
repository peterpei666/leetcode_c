#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumOperations(char* num)
{
    int t1,t2,m,n;
    int len=(int)strlen(num);
    m=len-1;
    while(m>=0&&num[m]!='0')
    {
        m--;
    }
    n=m-1;
    while(n>=0&&num[n]!='0'&&num[n]!='5')
    {
        n--;
    }
    t1=len-(n+2);
    m=len-1;
    while(m>=0&&num[m]!='5')
    {
        m--;
    }
    n=m-1;
    while(n>=0&&num[n]!='2'&&num[n]!='7')
    {
        n--;
    }
    if(n>=0)
    {
        t2=len-(n+2);
    }
    else
    {
        t2=len;
    }
    if(t1>t2)
    {
        return t2;
    }
    else
    {
        return t1;
    }
}
