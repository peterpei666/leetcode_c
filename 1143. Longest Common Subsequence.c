#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int longestCommonSubsequence(char* text1, char* text2)
{
    int a,b,i,j,temp;
    a=(int)strlen(text1);
    b=(int)strlen(text2);
    int** list=(int**)malloc((a+1)*sizeof(int*));
    for(i=0;i<=a;i++)
    {
        list[i]=(int*)malloc((b+1)*sizeof(int));
    }
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=b;j++)
        {
            if(i==0||j==0)
            {
                list[i][j]=0;
            }
            else if(text1[i-1]==text2[j-1])
            {
                list[i][j]=list[i-1][j-1]+1;
            }
            else
            {
                list[i][j]=max(list[i-1][j],list[i][j-1]);
            }
        }
    }
    temp=list[a][b];
    for(i=0;i<=a;i++)
    {
        free(list[i]);
    }
    free(list);
    return temp;
}
