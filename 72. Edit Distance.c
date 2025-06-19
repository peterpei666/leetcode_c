#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}
        
int minDistance(char* word1, char* word2)
{
    int i,j;
    int m=(int)strlen(word1);
    int n=(int)strlen(word2);
    short dp[m+1][n+1];
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(word1[i-1]==word2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    return dp[m][n];
}
