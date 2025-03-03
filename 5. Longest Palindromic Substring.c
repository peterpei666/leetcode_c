#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    int len=(int)strlen(s),i,j,mp=0,mr=0;
    char temp[2*len+2];
    for(i=0;i<len;i++)
    {
        temp[2*i]='*';
        temp[2*i+1]=*(s+i);
    }
    temp[2*len]='*';
    temp[2*len+1]='\0';
    for(i=0;i<2*len;i++)
    {
        j=0;
        while(i-j>=0&&i+j<=2*len&&temp[i-j]==temp[i+j])
        {
            j++;
        }
        if(j-1>=mr)
        {
            mr=j-1;
            mp=i;
        }
    }
    char* ans=(char*)malloc((mr+3)*sizeof(char));
    for(i=mp-mr,j=0;i<=mp+mr;i++)
    {
        if(temp[i]!='*')
        {
            ans[j]=temp[i];
            j++;
        }
    }
    ans[j]='\0';
    return ans;
}
