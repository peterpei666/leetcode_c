#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int price;
} node;

int compare(const void* p1,const void* p2)
{
    node* a=(node*)p1;
    node* b=(node*)p2;
    return a->day-b->day;
}

int minimumLines(int** s, int sz, int* stockPricesColSize)
{
    int i,count=1;
    if(sz==1)
    {
        return 0;
    }
    node* list=(node*)malloc(sizeof(node)*sz);
    for(i=0;i<sz;i++)
    {
        list[i]=(node){s[i][0],s[i][1]};
    }
    qsort(list,sz,sizeof(node),compare);
    for(i=2;i<sz;i++)
    {
        if((long long)(list[i-2].price-list[i-1].price)*(long long)(list[i-1].day-list[i].day)!=(long long)(list[i-1].price-list[i].price)*(long long)(list[i-2].day-list[i-1].day))
        {
            count++;
        }
    }
    free(list);
    return count;
}
