#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int findLUSlength(char* a, char* b)
{
    if(strcmp(a,b)==0)
    {
        return -1;
    }
    return maxi((int)strlen(a),(int)strlen(b));
}
