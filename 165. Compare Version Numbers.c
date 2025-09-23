#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareVersion(char* version1, char* version2)
{
    int m = (int)strlen(version1);
    int n = (int)strlen(version2);
    int i = 0, j = 0;
    while (i < m || j < n)
    {
        int temp1 = 0;
        while (i < m && version1[i] != '.')
        {
            temp1 = temp1 * 10 - '0' + version1[i];
            i++;
        }
        i++;
        int temp2 = 0;
        while (j < n && version2[j] != '.')
        {
            temp2 = temp2 * 10 - '0' + version2[j];
            j++;
        }
        j++;
        if (temp1 > temp2)
        {
            return 1;
        }
        if (temp1 < temp2)
        {
            return -1;
        }
    }
    return 0;
}
