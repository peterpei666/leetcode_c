#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s)
{
    int len=(int)strlen(s),i=0,value=0;
    if(strstr(s,"IV")||strstr(s,"IX"))
    {
        value-=2;
    }
    if(strstr(s,"XC")||strstr(s,"XL"))
    {
        value-=20;
    }
    if(strstr(s,"CD")||strstr(s,"CM"))
    {
        value-=200;
    }
    for(i=0;i<len;i++)
    {
        switch(*(s+i))
        {
            case 'M':
                value+=1000;
                break;
            case 'D':
                value+=500;
                break;
            case 'C':
                value+=100;
                break;
            case 'L':
                value+=50;
                break;
            case 'X':
                value+=10;
                break;
            case 'V':
                value+=5;
                break;
            case 'I':
                value+=1;
                break;
            default:
                break;
        }
    }
    return value;
}
