#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int findNthDigit(int n)
{
    long long i=1;
    long long base=9;
    long long num;
    char s[20];
    while(n>i*base)
    {
        n-=i*base;
        i++;
        base*=10;
    }
    num=pow(10,i-1)+(n-1)/i;
    sprintf(s,"%lld",num);
    return s[(n-1)%i]-'0';
}
