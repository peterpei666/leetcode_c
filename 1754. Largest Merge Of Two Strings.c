#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestMerge(char* word1, char* word2)
{
    int i=0,j=0,k=0;
    int n1=(int)strlen(word1);
    int n2=(int)strlen(word2);
    char* ret=(char*)malloc(n1+n2+1);
    while(i<n1||j<n2)
    {
        if(strcmp(word1+i,word2+j)>0)
        {
            ret[k]=word1[i];
            i++;
        }
        else
        {
            ret[k]=word2[j];
            j++;
        }
        k++;
    }
    ret[n1+n2]='\0';
    return ret;
}
