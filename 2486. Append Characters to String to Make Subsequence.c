#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int appendCharacters(char* s, char* t)
{
    int i,j=0;
    int n1=(int)strlen(s);
    int n2=(int)strlen(t);
    for(i=0;i<n1;i++)
    {
        if(j<n2&&s[i]==t[j])
        {
            j++;
        }
    }
    return n2-j;
}
