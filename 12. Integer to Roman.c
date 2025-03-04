#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int x)
{
    int value[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1},i;
    char* list[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char* roman=(char*)malloc(sizeof(char)*20);
    *roman='\0';
    for(i=0;i<13;i++)
    {
        while(x>=value[i])
        {
            x-=value[i];
            strcat(roman,list[i]);
        }
    }
    return roman;
}
