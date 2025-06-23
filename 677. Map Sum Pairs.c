#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int sz;
    char* list[50];
    int val[50];
} MapSum;


MapSum* mapSumCreate(void)
{
    MapSum* obj=(MapSum*)malloc(sizeof(MapSum));
    obj->sz=0;
    return obj;
}

void mapSumInsert(MapSum* obj, char* key, int val)
{
    int i;
    for(i=0;i<obj->sz;i++)
    {
        if(strcmp(obj->list[i],key)==0)
        {
            obj->val[i]=val;
            return;
        }
    }
    obj->list[obj->sz]=key;
    obj->val[obj->sz]=val;
    obj->sz++;
}

int mapSumSum(MapSum* obj, char* prefix)
{
    int i,sum=0;
    int n=(int)strlen(prefix);
    for(i=0;i<obj->sz;i++)
    {
        if(strncmp(prefix,obj->list[i],n)==0)
        {
            sum+=obj->val[i];
        }
    }
    return sum;
}

void mapSumFree(MapSum* obj)
{
    free(obj);
}
