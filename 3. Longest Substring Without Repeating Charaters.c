#include <stdio.h>
#include <stdbool.h>


int max(int i,int j)
{
    if(i>j)
    {
        return i;
    }
    else
    {
        return j;
    }
}

int lengthOfLongestSubstring(char* s)
{
    bool list[128]={false};
    int i=0,j=0,m=0;
    while(*(s+i)!='\0')
    {
        while(list[*(s+i)]==true&&j<i)
        {
            list[*(s+j)]=false;
            j++;
        }
        list[*(s+i)]=true;
        i++;
        m=max(m,i-j);
    }
    return m;
}
