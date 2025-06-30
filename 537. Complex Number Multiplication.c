#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* complexNumberMultiply(char* num1, char* num2)
{
    int r1,i1,r2,i2;
    int r,i;
    char ret[30];
    sscanf(num1,"%d+%di",&r1,&i1);
    sscanf(num2,"%d+%di",&r2,&i2);
    sprintf(ret,"%d+%di",r1*r2-i1*i2,r1*i2+r2*i1);
    return strdup(ret);
}
