#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreOfString(char* s)
{
    int i,score=0;
    int len=(int)strlen(s);
    for(i=1;i<len;i++)
    {
        score+=abs(s[i]-s[i-1]);
    }
    return score;
}
