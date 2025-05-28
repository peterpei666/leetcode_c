#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct
{
    int* list;
    int sz;
    int capacity;
} Solution;

Solution* solutionCreate(struct ListNode* head)
{
    Solution* obj=(Solution*)malloc(sizeof(Solution));
    obj->list=(int*)malloc(sizeof(int)*50);
    obj->sz=0;
    obj->capacity=50;
    while(head)
    {
        if(obj->sz==obj->capacity)
        {
            obj->capacity*=2;
            obj->list=(int*)realloc(obj->list,sizeof(int)*obj->capacity);
        }
        obj->list[obj->sz]=head->val;
        obj->sz++;
        head=head->next;
    }
    srand((unsigned int)time(NULL));
    return obj;
}

int solutionGetRandom(Solution* obj)
{
    return obj->list[rand()%obj->sz];
}

void solutionFree(Solution* obj)
{
    free(obj->list);
    free(obj);
}
