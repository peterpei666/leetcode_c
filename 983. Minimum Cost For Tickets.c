#include <stdio.h>
#include <stdlib.h>

int min(int a,int b,int c)
{
    int min=a;
    if(b<min)
    {
        min=b;
    }
    if(c<min)
    {
        min=c;
    }
    return min;
}

int mincostTickets(int* days,int daysSize,int* costs,int costsSize)
{
    int i,j,count=0,temp;
    int* list=(int*)calloc(days[daysSize-1]+1,sizeof(int));
    for(i=1;i<=days[daysSize-1];i++)
    {
        if(count<daysSize&&i==days[count]&&i<7)
        {
            list[i]=min(list[i-1]+costs[0],list[0]+costs[1],list[0]+costs[2]);
            count++;
        }
        else if(count<daysSize&&i==days[count]&&i<30)
        {
            list[i]=min(list[i-1]+costs[0],list[i-7]+costs[1],list[0]+costs[2]);
            count++;
        }
        else if(count<daysSize&&i==days[count])
        {
            list[i]=min(list[i-1]+costs[0],list[i-7]+costs[1],list[i-30]+costs[2]);
            count++;
        }
        else
        {
            list[i]=list[i-1];
        }
    }
    temp=list[days[daysSize-1]];
    free(list);
    return temp;
}
