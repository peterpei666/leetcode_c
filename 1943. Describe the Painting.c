#include <stdio.h>
#include <stdlib.h>

#define M 10083

typedef struct node
{
    int m;
    long long n;
    struct node* next;
} node;

typedef struct
{
    int m;
    long long n;
} p;

node* hashtable[M];
int count;

void initialize(void)
{
    int i;
    count=0;
    for(i=0;i<M;i++)
    {
        hashtable[i]=NULL;
    }
}

inline int hash_func(int m)
{
    return m*97%M;
}

node* create(int m,long long n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=n;
    newnode->next=NULL;
    return newnode;
}

node* find(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
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

void insert(int m,long long n)
{
    int hash=hash_func(m);
    node* newnode=create(m,n);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            prev=temp;
            temp=(node*)temp->next;
            free(prev);
        }
    }
}

int cmp(const void* p1,const void* p2)
{
    p* a=(p*)p1;
    p* b=(p*)p2;
    return a->m-b->m;
}

inline long long* help(int a,int b,long long c)
{
    long long* ret=(long long*)malloc(sizeof(long long)*3);
    ret[0]=a;
    ret[1]=b;
    ret[2]=c;
    return ret;
}

long long** splitPainting(int** segments, int n, int* segmentsColSize, int* returnSize, int** returnColumnSizes)
{
    int i,k,prev=-1;
    long long cur=0;
    node* temp;
    initialize();
    for(i=0;i<n;i++)
    {
        temp=find(segments[i][0]);
        if(temp)
        {
            temp->n+=segments[i][2];
        }
        else
        {
            count++;
            insert(segments[i][0],segments[i][2]);
        }
        temp=find(segments[i][1]);
        if(temp)
        {
            temp->n-=segments[i][2];
        }
        else
        {
            count++;
            insert(segments[i][1],-segments[i][2]);
        }
    }
    p* list=(p*)malloc(sizeof(p)*count);
    k=0;
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            list[k]=(p){temp->m,temp->n};
            k++;
            temp=temp->next;
        }
    }
    clear();
    qsort(list,count,sizeof(p),cmp);
    long long** ret=(long long**)malloc(sizeof(long long*)*count);
    k=0;
    for(i=0;i<count;i++)
    {
        if(prev==-1)
        {
            prev=list[i].m;
            cur+=list[i].n;
        }
        else
        {
            if(cur)
            {
                ret[k]=help(prev,list[i].m,cur);
                k++;
            }
            cur+=list[i].n;
            prev=list[i].m;
        }
    }
    *returnSize=k;
    *returnColumnSizes=(int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
    {
        (*returnColumnSizes)[i]=3;
    }
    return ret;
}
