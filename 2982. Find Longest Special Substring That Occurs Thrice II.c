#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(int length[26][3],int len,char a)
{
    int index=a-'a';
    if(len>length[index][0])
    {
        length[index][2]=length[index][1];
        length[index][1]=length[index][0];
        length[index][0]=len;
    }
    else if(len>length[index][1])
    {
        length[index][2]=length[index][1];
        length[index][1]=len;
    }
    else if(len>length[index][2])
    {
        length[index][2]=len;
    }
}

int find(int a,int b,int c)
{
    if(a==1&&c==0)
    {
        return 0;
    }
    if(a==b&&b==c)
    {
        return a;
    }
    if(a==b&&b!=c)
    {
        return a-1;
    }
    if(a==b+1)
    {
        return a-1;
    }
    return a-2;
}

int maximumLength(char* s)
{
    int i,len,count,max=0;
    char temp;
    len=(int)strlen(s);
    int length[26][3]={0};
    for(i=0;i<len;i++)
    {
        temp=s[i];
        count=1;
        while(s[i+1]==temp)
        {
            i++;
            count++;
        }
        insert(length,count,temp);
    }
    for(i=0;i<26;i++)
    {
        count=find(length[i][0],length[i][1],length[i][2]);
        if(count>max)
        {
            max=count;
        }
    }
    if(max==0)
    {
        return -1;
    }
    else
    {
        return max;
    }
}
