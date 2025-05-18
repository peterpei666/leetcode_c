#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int largestPalindrome(int n)
{
    if(n==1)
    {
        return 9;
    }
    const int mod=1337;
    int i,j,t;
    int low=pow(10,n-1);
    int high=pow(10,n)-1;
    long long temp;
    char str1[20];
    char str2[20];
    for(i=high;i>=low;i--)
    {
        sprintf(str1,"%d",i);
        for(j=0;j<n;j++)
        {
            str2[n-1-j]=str1[j];
        }
        str2[n]='\0';
        strcat(str1,str2);
        temp=atoll(str1);
        t=sqrtl(temp);
        for(j=high;j>=t;j--)
        {
            if(temp%j==0&&temp/j<=high&&temp/j>=low)
            {
                return temp%mod;
            }
        }
    }
    return 0;
}
