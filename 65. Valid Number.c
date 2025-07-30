#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline bool valid(int idx,char* s,int n)
{
    if(idx>0&&s[idx-1]>='0'&&s[idx-1]<='9')
    {
        return true;
    }
    if(idx+1<n&&s[idx+1]>='0'&&s[idx+1]<='9')
    {
        return true;
    }
    return false;
}

bool isNumber(char* s)
{
    int n=(int)strlen(s);
    bool dot=false;
    bool e=false;
    bool digit=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            digit=true;
        }
        else if(s[i]=='.')
        {
            if(dot||!valid(i,s,n))
            {
                return false;
            }
            dot=true;
        }
        else if(s[i]=='e'||s[i]=='E')
        {
            if(e||!digit)
            {
                return false;
            }
            else
            {
                e=true;
                dot=true;
                digit=false;
            }
        }
        else if(s[i]=='+'||s[i]=='-')
        {
            if(i>0&&s[i-1]!='e'&&s[i-1]!='E')
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return digit;
}
