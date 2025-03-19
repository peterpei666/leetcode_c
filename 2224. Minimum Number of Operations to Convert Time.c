#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertTime(char* current, char* correct)
{
    int h1,h2,min1,min2,temp,count=0;
    sscanf(current,"%d:%d",&h1,&min1);
    sscanf(correct,"%d:%d",&h2,&min2);
    temp=(h2-h1)*60+min2-min1;
    count+=temp/60;
    temp%=60;
    count+=temp/15;
    temp%=15;
    count+=temp/5;
    count+=temp%5;
    return count;
}
