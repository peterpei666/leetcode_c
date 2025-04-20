#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shiftingLetters(char* s, int* shifts, int shiftsSize)
{
    int i,len,current=0;
    len=(int)strlen(s);
    for(i=len-1;i>=0;i--)
    {
        current+=shifts[i]%26;
        current%=26;
        s[i]='a'+(s[i]-'a'+current)%26;
    }
    return s;
}
