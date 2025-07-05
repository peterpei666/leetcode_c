#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* list;
    int sz;
    int capacity;
} stack;

static inline stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(int*)malloc(sizeof(int)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

static inline void push(stack* s,int n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
    }
    s->list[s->sz]=n;
    s->sz++;
}

static inline int top(stack* s)
{
    if(s->sz==0)
    {
        return -1;
    }
    else
    {
        return s->list[s->sz-1];
    }
}

static inline void pop(stack* s)
{
    if(s->sz)
    {
        s->sz--;
        if(s->sz/100*100+100!=s->capacity)
        {
            s->capacity=s->sz/100*100+100;
            s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
        }
    }
}

static inline void clear(stack* s)
{
    free(s->list);
    free(s);
}

void process(int* maxHeights,int n,long long f[])
{
    int i,t;
    long long sum=0;
    stack* stk=initialize();
    push(stk,-1);
    for(i=0;i<n;i++)
    {
        while(stk->sz>1&&maxHeights[top(stk)]>maxHeights[i])
        {
            t=top(stk);
            pop(stk);
            sum-=1LL*(t-top(stk))*maxHeights[t];
        }
        sum+=1LL*(i-top(stk))*maxHeights[i];
        push(stk,i);
        f[i]=sum;
    }
    clear(stk);
}

static inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

static inline void reverse(int* arr,int n)
{
    int l=0,r=n-1;
    while(l<r)
    {
        swap(&arr[l],&arr[r]);
        l++;
        r--;
    }
}

static inline long long max(long long a,long long b)
{
    return a>b?a:b;
}

long long maximumSumOfHeights(int* maxHeights, int n)
{
    int i;
    long long ans=0;
    long long prefix[n];
    long long suffix[n];
    process(maxHeights,n,prefix);
    reverse(maxHeights,n);
    process(maxHeights,n,suffix);
    for(i=0;i<n;i++)
    {
        ans=max(ans,prefix[i]+suffix[n-1-i]-maxHeights[n-1-i]);
    }
    return ans;
}
