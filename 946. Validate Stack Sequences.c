#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int i,j=0,head=-1;
    int* stack=(int*)malloc(sizeof(int)*pushedSize);
    for(i=0;i<pushedSize;i++)
    {
        head++;
        stack[head]=pushed[i];
        while(head>=0&&j<poppedSize&&popped[j]==stack[head])
        {
            head--;
            j++;
        }
    }
    if(j==poppedSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
