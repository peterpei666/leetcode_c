#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int secondHighest(char* s)
{
    int i,m1=-1,m2=-1;
    int n=(int)strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(s[i]-'0'>m1)
            {
                m2=m1;
                m1=s[i]-'0';
            }
            else if(s[i]-'0'!=m1&&s[i]-'0'>m2)
            {
                m2=s[i]-'0';
            }
        }
    }
    return m2;
}
