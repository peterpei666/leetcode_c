#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline bool number(char c)
{
    return c>='0'&&c<='9';
}

static inline bool letter(char c)
{
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

static inline bool vowel(char c)
{
    if(c>='A'&&c<='Z')
    {
        c=c-'A'+'a';
    }
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

bool isValid(char* word)
{
    int n=(int)strlen(word);
    if(n<3)
    {
        return false;
    }
    bool v=false,c=false;
    for(int i=0;i<n;i++)
    {
        if(number(word[i]))
        {
            continue;
        }
        if(letter(word[i]))
        {
            if(vowel(word[i]))
            {
                v=true;
            }
            else
            {
                c=true;
            }
        }
        else
        {
            return false;
        }
    }
    return v&&c;
}
