#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int m(int arr[4])
{
    return max(max(arr[0],arr[1]),max(arr[2],arr[3]));
}

int maxDistance(char* s, int k)
{
    int cur[4]={0};
    int temp[4]={0};
    int i,ans=0;
    int n=(int)strlen(s);
    for(i=0;i<n;i++)
    {
        switch(s[i])
        {
            case 'N':
                cur[0]++;
                cur[1]++;
                if(temp[2]<k)
                {
                    cur[2]++;
                    temp[2]++;
                }
                else
                {
                    cur[2]--;
                }
                if(temp[3]<k)
                {
                    cur[3]++;
                    temp[3]++;
                }
                else
                {
                    cur[3]--;
                }
                ans=max(ans,m(cur));
                break;
            case 'S':
                cur[2]++;
                cur[3]++;
                if(temp[0]<k)
                {
                    cur[0]++;
                    temp[0]++;
                }
                else
                {
                    cur[0]--;
                }
                if(temp[1]<k)
                {
                    cur[1]++;
                    temp[1]++;
                }
                else
                {
                    cur[1]--;
                }
                ans=max(ans,m(cur));
                break;
            case 'W':
                cur[1]++;
                cur[3]++;
                if(temp[0]<k)
                {
                    cur[0]++;
                    temp[0]++;
                }
                else
                {
                    cur[0]--;
                }
                if(temp[2]<k)
                {
                    cur[2]++;
                    temp[2]++;
                }
                else
                {
                    cur[2]--;
                }
                ans=max(ans,m(cur));
                break;
            case 'E':
                cur[0]++;
                cur[2]++;
                if(temp[1]<k)
                {
                    cur[1]++;
                    temp[1]++;
                }
                else
                {
                    cur[1]--;
                }
                if(temp[3]<k)
                {
                    cur[3]++;
                    temp[3]++;
                }
                else
                {
                    cur[3]--;
                }
                ans=max(ans,m(cur));
                break;
        }
    }
    return ans;
}
