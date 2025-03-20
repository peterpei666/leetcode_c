#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(char* str,int* zero,int* one)
{
    int i,len;
    len=(int)strlen(str);
    *zero=0;
    *one=0;
    for(i=0;i<len;i++)
    {
        if(str[i]=='0')
        {
            (*zero)++;
        }
        else if(str[i]=='1')
        {
            (*one)++;
        }
    }
}

int findMaxForm(char** strs, int strsSize, int m, int n)
{
    int i,j,k,zero,one,ans;
    int** max=(int**)malloc((m+1)*sizeof(int*));
    for(i=0;i<m+1;i++)
    {
        max[i]=(int*)calloc(n+1,sizeof(int));
    }
    for(k=0;k<strsSize;k++)
    {
        count(strs[k],&zero,&one);
        for(i=m;i>=zero;i--)
        {
            for(j=n;j>=one;j--)
            {
                max[i][j]=((1+max[i-zero][j-one])>max[i][j])?1+max[i-zero][j-one]:max[i][j];
            }
        }
    }
    ans=max[m][n];
    for(i=0;i<m+1;i++)
    {
        free(max[i]);
    }
    free(max);
    return ans;
}

