#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2)
{
    return (int)strlen(*(char**)p1)-(int)strlen(*(char**)p2);
}

char** stringMatching(char** words, int wordsSize, int* returnSize)
{
    int count=0,i,j;
    char** ret=(char**)malloc(sizeof(char*)*wordsSize);
    qsort(words,wordsSize,sizeof(char*),compare);
    for(i=0;i<wordsSize;i++)
    {
        for(j=i+1;j<wordsSize;j++)
        {
            if(strstr(words[j],words[i]))
            {
                ret[count]=words[i];
                count++;
                break;
            }
        }
    }
    *returnSize=count;
    return ret;
}
