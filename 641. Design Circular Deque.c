#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* list;
    int size;
    int capacity;
    int front;
    int rear;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k)
{
    MyCircularDeque* obj=(MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->size=0;
    obj->capacity=k;
    obj->front=0;
    obj->rear=0;
    obj->list=(int*)malloc(sizeof(int)*k);
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
    return obj->size==0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj)
{
    return obj->size>=obj->capacity;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
    if(myCircularDequeIsFull(obj))
    {
        return false;
    }
    obj->front=(obj->front-1+obj->capacity)%obj->capacity;
    obj->size++;
    obj->list[obj->front]=value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
    if(myCircularDequeIsFull(obj))
    {
        return false;
    }
    obj->list[obj->rear]=value;
    obj->rear=(obj->rear+1)%obj->capacity;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj))
    {
        return false;
    }
    obj->size--;
    obj->front=(obj->front+1)%obj->capacity;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj))
    {
        return false;
    }
    obj->size--;
    obj->rear=(obj->rear-1+obj->capacity)%obj->capacity;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj))
    {
        return -1;
    }
    return obj->list[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj)
{
    if(myCircularDequeIsEmpty(obj))
    {
        return -1;
    }
    return obj->list[(obj->rear-1+obj->capacity)%obj->capacity];
}

void myCircularDequeFree(MyCircularDeque* obj)
{
    free(obj->list);
    free(obj);
}
