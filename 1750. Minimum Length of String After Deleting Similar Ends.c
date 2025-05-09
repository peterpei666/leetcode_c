#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumLength(char* s)
{
    int l=0;
    int r=(int)strlen(s)-1;
    char c;
    while(l<r&&s[l]==s[r])
    {
        c=s[l];
        while(l<=r&&s[l]==c)
        {
            l++;
        }
        while(r>l&&s[r]==c)
        {
            r--;
        }
    }
    return r-l+1;
}
