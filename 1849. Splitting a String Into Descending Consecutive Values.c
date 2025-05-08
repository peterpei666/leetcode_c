#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const long long MAX=999999999999;

bool dfs(char* s,long long prev,int index,int count,int len)
{
    if(index==len)
    {
        return count>1;
    }
    int i;
    long long num=0;
    for(i=index;i<len;i++)
    {
        num=num*10+s[i]-'0';
        if(num>MAX)
        {
            break;
        }
        if(num>=prev&&prev!=-1)
        {
            break;
        }
        if(num==prev-1||prev==-1)
        {
            if(dfs(s,num,i+1,count+1,len))
            {
                return true;
            }
        }
    }
    return false;
}

bool splitString(char* s)
{
    int len=(int)strlen(s);
    if(len<=1)
    {
        return false;
    }
    return dfs(s,-1,0,0,len);
}
