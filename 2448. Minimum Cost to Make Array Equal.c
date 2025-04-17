#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int cost;
} pair;

inline long long mini(long long a,long long b)
{
    return a>b?b:a;
}

int compare(const void* p1,const void* p2)
{
    pair* a=(pair*)p1;
    pair* b=(pair*)p2;
    return a->num-b->num;
}

long long minCost(int* nums, int numsSize, int* cost, int costSize)
{
    int i,j;
    long long min=0,l=0,r=0,total=0,temp=0;
    pair* list=(pair*)malloc(sizeof(pair)*numsSize);
    for(i=0;i<numsSize;i++)
    {
        list[i].num=nums[i];
        list[i].cost=cost[i];
    }
    qsort(list,numsSize,sizeof(pair),compare);
    if(list[0].num==list[numsSize-1].num)
    {
        return 0;
    }
    for(i=0;i<numsSize;i++)
    {
        total+=(long long)list[i].cost;
        temp+=(long long)(list[i].num-list[0].num)*(long long)list[i].cost;
    }
    min=temp;
    r=total;
    j=0;
    while(j<numsSize&&list[j].num==list[0].num)
    {
        l+=(long long)list[j].cost;
        j++;
    }
    for(i=list[0].num+1;i<=list[numsSize-1].num;i++)
    {
        while(j<numsSize&&list[j].num<i)
        {
            l+=(long long)list[j].cost;
            j++;
        }
        r=total-l;
        temp+=-r+l;
        min=mini(min,temp);
    }
    free(list);
    return min;
}
