#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestGoodInteger(char* num)
{
    int n=(int)strlen(num);
    char* ans=(char*)malloc(4);
    ans[0]='\0';
    ans[3]='\0';
    for(int i=0;i<n-2;i++)
    {
        if(num[i]==num[i+1]&&num[i]==num[i+2])
        {
            if(ans[0]=='\0'||ans[0]<num[i])
            {
                memset(ans,num[i],3);
            }
        }
    }
    return ans;
}
