#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int cost(int mins,int secs,int startAt,int moveCost,int pushCost)
{
    if(mins>99||mins<0||secs>99|secs<0)
    {
        return INT_MAX;
    }
    int i,ret=0;
    char cur='0'+startAt;
    char s[10];
    sprintf(s,"%d",mins*100+secs);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==cur)
        {
            ret+=pushCost;
        }
        else
        {
            ret+=moveCost+pushCost;
            cur=s[i];
        }
    }
    return ret;
}

int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
{
    int mins=targetSeconds/60;
    int secs=targetSeconds%60;
    return min(cost(mins,secs,startAt,moveCost,pushCost),cost(mins-1,secs+60,startAt,moveCost,pushCost));
}
