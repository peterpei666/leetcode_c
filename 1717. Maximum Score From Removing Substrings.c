#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int maximumGain(char* s, int x, int y)
{
    int i,j,ans=0;
    char temp1[100000];
    char temp2[100000];
    int n=(int)strlen(s);
    if(y>x)
    {
        swap(&x,&y);
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                s[i]='b';
            }
            else if(s[i]=='b')
            {
                s[i]='a';
            }
        }
    }
    for(i=0,j=0;i<n;i++)
    {
        if(s[i]=='b'&&j&&temp1[j-1]=='a')
        {
            j--;
            ans+=x;
        }
        else
        {
            temp1[j]=s[i];
            j++;
        }
    }
    n=j;
    for(i=0,j=0;i<n;i++)
    {
        if(temp1[i]=='a'&&j&&temp2[j-1]=='b')
        {
            j--;
            ans+=y;
        }
        else
        {
            temp2[j]=temp1[i];
            j++;
        }
    }
    return ans;
}
