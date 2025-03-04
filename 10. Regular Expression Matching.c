#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s,char* p)
{
    if(!*p)
    {
        return !*s;
    }
    bool first_match=*s&&(*s==*p||*p=='.');
    if(*(p+1)=='*')
    {
        return isMatch(s,p+2)||(first_match&&isMatch(++s,p));
    }
    else
    {
        return first_match&&isMatch(++s,++p);
    }
}
