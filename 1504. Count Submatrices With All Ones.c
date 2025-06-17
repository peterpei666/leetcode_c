#include <stdio.h>
#include <stdlib.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int numSubmat(int** mat, int m, int* matColSize)
{
    int i,j,k,temp,ans;
    int n=matColSize[0];
    int dp[m][n];
    for(i=0;i<m;i++)
    {
        dp[i][0]=mat[i][0];
    }
    for(i=0;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=dp[i][j-1]+1;
            }
        }
    }
    ans=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
        {
            temp=dp[i][j];
            for(k=i;k>=0;k--)
            {
                temp=min(temp,dp[k][j]);
                if(temp==0)
                {
                    break;
                }
                ans+=temp;
            }
        }
    }
    return ans;
}
