#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findWordsContaining(char** words, int n, char x, int* returnSize)
{
    int i,j,len;
    int k=0;
    int* ret=(int*)malloc(sizeof(int)*50);
    for(i=0;i<n;i++)
    {
        len=(int)strlen(words[i]);
        for(j=0;j<len;j++)
        {
            if(words[i][j]==x)
            {
                ret[k]=i;
                k++;
                break;
            }
        }
    }
    *returnSize=k;
    return ret;
}
