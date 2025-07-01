#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int possibleStringCount(char* word)
{
    int i,ans=1;
    int n=(int)strlen(word);
    for(i=1;i<n;i++)
    {
        if(word[i]==word[i-1])
        {
            ans++;
        }
    }
    return ans;
}
