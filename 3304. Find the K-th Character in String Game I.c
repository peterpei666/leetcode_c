#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char kthCharacter(int k)
{
    int i,len;
    char temp;
    char* current=(char*)malloc(sizeof(char)*513);
    char* next=(char*)malloc(sizeof(char)*513);
    current[0]='a';
    current[1]='\0';
    while(strlen(current)<k)
    {
        strcpy(next,current);
        len=(int)strlen(next);
        for(i=0;i<len;i++)
        {
            next[i]++;
        }
        strcat(current,next);
    }
    temp=current[k-1];
    free(next);
    free(current);
    return temp;
}
