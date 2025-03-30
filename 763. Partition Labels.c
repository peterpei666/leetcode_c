#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* partitionLabels(char* s, int* returnSize)
{
    int len=(int)strlen(s);
    int size=0,i,capacity=10;
    int start,end;
    int* last=(int*)malloc(sizeof(int)*26);
    int* result=(int*)malloc(sizeof(int)*capacity);
    for(i=0;i<26;i++)
    {
        last[i]=-1;
    }
    for(i=0;i<len;i++)
    {
        last[s[i]-'a']=i;
    }
    start=0;
    end=0;
    for(i=0;i<len;i++)
    {
        if(last[s[i]-'a']>end)
        {
            end=last[s[i]-'a'];
        }
        if(i==end)
        {
            result[size]=end-start+1;
            size++;
            if(size>=capacity-2)
            {
                capacity+=10;
                result=(int*)realloc(result,capacity*sizeof(int));
            }
            start=end+1;
        }
    }
    *returnSize=size;
    free(last);
    return result;
}
