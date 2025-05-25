#include <stdio.h>
#include <stdlib.h>

int numFriendRequests(int* ages, int n)
{
    int cnt=0,i,j;
    int age[121]={0};
    for(i=0;i<n;i++)
    {
        age[ages[i]]++;
    }
    for(i=1;i<121;i++)
    {
        if(age[i]==0)
        {
            continue;
        }
        for(j=1;j<=i;j++)
        {
            if(age[j]==0)
            {
                continue;
            }
            if(i*0.5+7>=j)
            {
                continue;
            }
            if(i==j)
            {
                cnt+=age[i]*(age[j]-1);
            }
            else
            {
                cnt+=age[i]*age[j];
            }
        }
    }
    return cnt;
}
