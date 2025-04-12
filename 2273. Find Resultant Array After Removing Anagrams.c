#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** removeAnagrams(char** words, int wordsSize, int* returnSize)
{
    int i,j,m,len;
    int prev[26],curr[26];
    for(i=0;i<26;i++)
    {
        prev[i]=0;
        curr[i]=0;
    }
    len=(int)strlen(words[0]);
    for(m=0;m<len;m++)
    {
        prev[words[0][m]-'a']++;
    }
    for(i=1,j=1;i<wordsSize;i++)
    {
        len=(int)strlen(words[i]);
        for(m=0;m<len;m++)
        {
            curr[words[i][m]-'a']++;
        }
        for(m=0;m<26;m++)
        {
            if(prev[m]!=curr[m])
            {
                break;
            }
        }
        if(m!=26)
        {
            words[j]=words[i];
            j++;
            memcpy(prev,curr,26*sizeof(int));
        }
        for(m=0;m<26;m++)
        {
            curr[m]=0;
        }
    }
    *returnSize=j;
    return words;
}
