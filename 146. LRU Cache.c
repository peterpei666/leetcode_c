#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//list
struct node
{
    int key;
    int val;
    struct node* prev;
    struct node* next;
};

typedef struct
{
    struct node* head;
    struct node* tail;
    int sz;
} LinkedList;

struct node* create(int key,int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=key;
    newnode->val=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

LinkedList* LinkedListCreate(void)
{
    LinkedList* obj=(LinkedList*)malloc(sizeof(LinkedList));
    obj->sz=0;
    obj->head=create(0,0);
    obj->tail=create(0,0);
    obj->head->next=obj->tail;
    obj->tail->prev=obj->head;
    return obj;
}

void myLinkedListAddAtHead(LinkedList* obj, int key, int val)
{
    struct node* temp=create(key,val);
    temp->next=obj->head->next;
    temp->prev=obj->head;
    obj->head->next->prev=temp;
    obj->head->next=temp;
    obj->sz++;
}

struct node* back(LinkedList* obj)
{
    return obj->tail->prev;
}

void pop_back(LinkedList* obj)
{
    struct node* temp=obj->tail->prev;
    temp->prev->next=obj->tail;
    obj->tail->prev=temp->prev;
    free(temp);
    obj->sz--;
}
void splice(LinkedList* obj, struct node* temp)
{
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    temp->next=obj->head->next;
    temp->prev=obj->head;
    obj->head->next->prev=temp;
    obj->head->next=temp;
}

void LinkedListFree(LinkedList* obj)
{
    struct node* temp;
    struct node* prev;
    temp=obj->head;
    while(temp)
    {
        prev=temp;
        temp=temp->next;
        free(prev);
    }
    free(obj);
}
//hash table
#define M 5083

typedef struct hashnode
{
    int m;
    struct node* it;
    struct hashnode* next;
} hashnode;

void initialize(hashnode*** list)
{
    int i;
    *list=(hashnode**)malloc(sizeof(hashnode*)*M);
    for(i=0;i<M;i++)
    {
        (*list)[i]=NULL;
    }
}

inline int hash_func(int m)
{
    return m*97%M;
}

hashnode* create_hashnode(int m,struct node* it)
{
    hashnode* newnode=(hashnode*)malloc(sizeof(hashnode));
    newnode->m=m;
    newnode->it=it;
    newnode->next=NULL;
    return newnode;
}

hashnode* find(int m,hashnode** hashtable)
{
    int hash=hash_func(m);
    hashnode* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void insert(int m,struct node* it,hashnode** hashtable)
{
    int hash=hash_func(m);
    hashnode* newnode=create_hashnode(m,it);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

void erase(int m,hashnode** hashtable)
{
    int hash=hash_func(m);
    hashnode* temp=hashtable[hash];
    hashnode* prev=NULL;
    while(temp&&temp->m!=m)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        hashtable[hash]=temp->next;
    }
    else
    {
        prev->next=temp->next;
    }
    free(temp);
}

void clear(hashnode** hashtable)
{
    int i;
    hashnode* temp;
    hashnode* prev;
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            prev=temp;
            temp=temp->next;
            free(prev);
        }
    }
    free(hashtable);
}
//LRU cache
typedef struct
{
    hashnode** hashtable;
    LinkedList* list;
    int c;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity)
{
    LRUCache* obj=(LRUCache*)malloc(sizeof(LRUCache));
    obj->c=capacity;
    initialize(&obj->hashtable);
    obj->list=LinkedListCreate();
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
    hashnode* temp=find(key,obj->hashtable);
    if(temp)
    {
        splice(obj->list,temp->it);
        return temp->it->val;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
    int oldkey;
    hashnode* temp=find(key,obj->hashtable);
    if(temp)
    {
        temp->it->val=value;
        splice(obj->list,temp->it);
    }
    else
    {
        if(obj->list->sz==obj->c)
        {
            oldkey=back(obj->list)->key;
            pop_back(obj->list);
            erase(oldkey,obj->hashtable);
        }
        myLinkedListAddAtHead(obj->list,key,value);
        insert(key,obj->list->head->next,obj->hashtable);
    }
}

void lRUCacheFree(LRUCache* obj)
{
    LinkedListFree(obj->list);
    clear(obj->hashtable);
    free(obj);
}
