#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maximumNumber(char* num, int* change, int changeSize)
{
    int n=(int)strlen(num);
    int i=0;
    while(i<n&&change[num[i]-'0']<=num[i]-'0')
    {
        i++;
    }
    while(i<n&&change[num[i]-'0']>=num[i]-'0')
    {
        num[i]=change[num[i]-'0']+'0';
        i++;
    }
    return num;
}
