#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(char* s)
{
    char min='z';
    int count=0,i,len;
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]<min)
        {
            min=s[i];
            count=1;
        }
        else if(s[i]==min)
        {
            count++;
        }
    }
    return count;
}

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize)
{
    int i,j,temp;
    int* count=(int*)calloc(sizeof(int),queriesSize);
    int* w=(int*)malloc(sizeof(int)*wordsSize);
    for(i=0;i<wordsSize;i++)
    {
        w[i]=f(words[i]);
    }
    for(i=0;i<queriesSize;i++)
    {
        temp=f(queries[i]);
        for(j=0;j<wordsSize;j++)
        {
            if(w[j]>temp)
            {
                count[i]++;
            }
        }
    }
    *returnSize=queriesSize;
    return count;
}
