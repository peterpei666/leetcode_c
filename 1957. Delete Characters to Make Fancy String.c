#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* makeFancyString(char* s)
{
    int j=1,n=(int)strlen(s);
    char* ans=(char*)malloc(n+1);
    ans[0]=s[0];
    for(int i=1,cnt=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            cnt=1;
        }
        else
        {
            cnt++;
        }
        if(cnt<=2)
        {
            ans[j]=s[i];
            j++;
        }
    }
    ans[j]='\0';
    return ans;
}
