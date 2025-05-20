#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minAddToMakeValid(char* s)
{
    int i,len;
    int ans=0,count=0;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        switch(s[i])
        {
            case '(':
                count++;
                break;
            case ')':
                if(count==0)
                {
                    ans++;
                }
                else
                {
                    count--;
                }
                break;
        }
    }
    return ans+count;
}
