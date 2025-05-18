#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int maxPalindromesAfterOperations(char** words, int n)
{
    int i,j;
    int pair=0;
    int odd=0;
    int len[n];
    for(i=0;i<n;i++)
    {
        len[i]=(int)strlen(words[i]);
        for(j=0;j<len[i];j++)
        {
            if(odd&(1<<(words[i][j]-'a')))
            {
                pair++;
            }
            odd^=1<<(words[i][j]-'a');
        }
    }
    qsort(len,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
        pair-=len[i]/2;
        if(pair<0)
        {
            return i;
        }
    }
    return n;
}
