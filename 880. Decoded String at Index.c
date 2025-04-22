#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decodeAtIndex(char* s, int k)
{
    int i,j,len;
    static char ret[2];
    long long l=0;
    len=(int)strlen(s);
    ret[1]='\0';
    for(i=0;i<len;i++)
    {
        if(s[i]>'0'&&s[i]<='9')
        {
            l*=s[i]-'0';
        }
        else
        {
            l++;
        }
    }
    for(i=len-1;i>=0;i--)
    {
        if(s[i]>'0'&&s[i]<='9')
        {
            l/=s[i]-'0';
            k%=l;
        }
        else
        {
            if(k==0||l==k)
            {
                ret[0]=s[i];
                return ret;
            }
            l--;
        }
    }
    ret[0]='\0';
    return ret;
}
