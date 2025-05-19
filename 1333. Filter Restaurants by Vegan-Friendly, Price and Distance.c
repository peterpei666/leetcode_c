#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int rate;
} node;

int cmp(const void* p1,const void* p2)
{
    node* a=(node*)p1;
    node* b=(node*)p2;
    return a->rate==b->rate?b->id-a->id:b->rate-a->rate;
}

int* filterRestaurants(int** restaurants, int n, int* restaurantsColSize, int v, int mp, int md, int* returnSize)
{
    int i;
    int sz=0;
    int capacity=10;
    node* list=(node*)malloc(sizeof(node)*capacity);
    if(v)
    {
        for(i=0;i<n;i++)
        {
            if(restaurants[i][2]==v&&restaurants[i][3]<=mp&&restaurants[i][4]<=md)
            {
                if(sz>=capacity)
                {
                    capacity*=2;
                    list=(node*)realloc(list,sizeof(node*)*capacity);
                }
                list[sz]=(node){restaurants[i][1],restaurants[i][0]};
                sz++;
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(restaurants[i][3]<=mp&&restaurants[i][4]<=md)
            {
                if(sz>=capacity)
                {
                    capacity*=2;
                    list=(node*)realloc(list,sizeof(node*)*capacity);
                }
                list[sz]=(node){restaurants[i][1],restaurants[i][0]};
                sz++;
            }
        }
    }
    qsort(list,sz,sizeof(node),cmp);
    int* ret=(int*)malloc(sizeof(int)*sz);
    for(i=0;i<sz;i++)
    {
        ret[i]=list[i].id;
    }
    *returnSize=sz;
    return ret;
}
