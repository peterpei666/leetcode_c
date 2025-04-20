#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize)
{
    int i,len,current=0;
    len=(int)strlen(s);
    int* list=(int*)calloc(sizeof(int),len);
    for(i=0;i<shiftsSize;i++)
    {
        if(shifts[i][2]==1)
        {
            list[shifts[i][0]]++;
            if(shifts[i][1]+1<len)
            {
                list[shifts[i][1]+1]--;
            }
        }
        else
        {
            list[shifts[i][0]]--;
            if(shifts[i][1]+1<len)
            {
                list[shifts[i][1]+1]++;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        current+=list[i];
        list[i]=current;
    }
    for(i=0;i<len;i++)
    {
        list[i]=(list[i]%26+26)%26;
        s[i]='a'+(s[i]-'a'+list[i])%26;
    }
    free(list);
    return s;
}
