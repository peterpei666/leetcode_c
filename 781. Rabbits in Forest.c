#include <stdio.h>
#include <stdlib.h>

int numRabbits(int* answers, int answersSize)
{
    int i,count=0;
    int list[1000]={0};
    for(i=0;i<answersSize;i++)
    {
        if(list[answers[i]]==0)
        {
            count+=answers[i]+1;
        }
        list[answers[i]]++;
        list[answers[i]]%=answers[i]+1;
    }
    return count;
}
