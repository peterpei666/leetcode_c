#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reversePrefix(char* word, char ch)
{
    int len=(int)strlen(word);
    int i,n;
    char temp;
    for(n=0;n<len;n++)
    {
        if(ch==word[n])
        {
            break;
        }
    }
    if(n==len)
    {
        return word;
    }
    for(i=0;i<=n/2;i++)
    {
        temp=word[i];
        word[i]=word[n-i];
        word[n-i]=temp;
    }
    return word;
}
