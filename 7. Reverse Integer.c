#include <stdio.h>
#include <math.h>

int reverse(int x)
{
    int m=0,f1=0,list[10]={0},ans=0,i;
    if(x==-2147483648)
    {
        return 0;
    }
    if(x<0)
    {
        f1=1;
    }
    x=(x>0?x:-x);
    while(x)
    {
        list[m]=x%10;
        x/=10;
        m++;
    }
    if(m<=9)
    {
        for(i=0;i<m;i++)
        {
            ans+=list[i]*(int)pow(10,m-i-1);
        }
        if(f1)
        {
            ans*=-1;
        }
    }
    else
    {
        if(f1==0)
        {
            if(list[0]>2)
            {
                ans=0;
            }
            else
            {
                for(i=0;i<m;i++)
                {
                    ans+=list[i]*(int)pow(10,m-i-1);
                }
                if(ans<0)
                {
                    ans=0;
                }
            }
        }
        else
        {
            if(list[0]>2)
            {
                ans=0;
            }
            else
            {
                for(i=0;i<m;i++)
                {
                    ans+=list[i]*(int)pow(10,m-i-1);
                }
                if(ans<0)
                {
                    ans=0;
                }
                if(f1)
                {
                    ans*=-1;
                }
            }
        }
    }
    return ans;
}

