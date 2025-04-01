#include <stdio.h>
#include <stdlib.h>

long long max(long long a,long long b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize)
{
    long long* dp=(long long*)calloc(questionsSize,sizeof(long long));
    int i;
    long long temp;
    dp[questionsSize-1]=questions[questionsSize-1][0];
    for(i=questionsSize-2;i>=0;i--)
    {
        if(questions[i][1]+i+1<questionsSize)
        {
            dp[i]=max(dp[i+1],dp[questions[i][1]+i+1]+questions[i][0]);
        }
        else
        {
            dp[i]=max(dp[i+1],questions[i][0]);
        }
    }
    temp=dp[0];
    free(dp);
    return temp;
}
