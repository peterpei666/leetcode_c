#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeAlmostEqualCharacters(char* word)
{
    int i=0,count=0;
    int len=(int)strlen(word);
    while(i<len)
    {
        if(i+1<len&&(word[i+1]==word[i]||word[i+1]==word[i]+1||word[i+1]==word[i]-1))
        {
            count++;
            i+=2;
        }
        else
        {
            i++;
        }
    }
    return count;
}
