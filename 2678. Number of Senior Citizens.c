#include <stdio.h>
#include <stdlib.h>

int countSeniors(char** details, int detailsSize)
{
    int i,count=0;
    for(i=0;i<detailsSize;i++)
    {
        if(10*(details[i][11]-'0')+details[i][12]-'0'>60)
        {
            count++;
        }
    }
    return count;
}
