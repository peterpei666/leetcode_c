#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10083

typedef struct
{
    int arr[10];
    struct node* next;
} node;

node* hashtable[M];

void initialize(void)
{
    int i;
    for(i=0;i<M;i++)
    {
        hashtable[i]=NULL;
    }
}

int hash_func(int arr[10])
{
    int hash=0,i;
    for(i=0;i<10;i++)
    {
        hash+=arr[i];
        hash*=31;
        hash%=M;
    }
    return hash;
}

node* create(int arr[10])
{
    node* newnode=(node*)malloc(sizeof(node));
    memcpy(newnode->arr,arr,10*sizeof(int));
    newnode->next=NULL;
    return newnode;
}

int find(int arr[10])
{
    int hash=hash_func(arr);
    int i;
    node* temp=hashtable[hash];
    while(temp)
    {
        for(i=0;i<10;i++)
        {
            if(arr[i]!=temp->arr[i])
            {
                break;
            }
        }
        if(i==10)
        {
            return 1;
        }
        temp=(node*)temp->next;
    }
    return 0;
}

void insert(int arr[10])
{
    int hash=hash_func(arr);
    node* newnode=create(arr);
    newnode->next=(struct node*)hashtable[hash];
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

long long factorial(int x)
{
    long long f=1;
    while(x)
    {
        f*=x;
        x--;
    }
    return f;
}

long long choose(int x,int n)
{
    if(x==0||x==n)
    {
        return 1;
    }
    long long c=1,i;
    for(i=n;i>n-x;i--)
    {
        c*=i;
    }
    return c/factorial(x);
}

long long rearrange(long long temp)
{
    int i,m=0,n;
    long long count=1,t=1;
    int arr[10]={0};
    while(temp)
    {
        arr[temp%10]++;
        temp/=10;
        m++;
    }
    if(find(arr))
    {
        return 0;
    }
    insert(arr);
    n=m;
    for(i=0;i<10;i++)
    {
        count*=choose(arr[i],n);
        n-=arr[i];
    }
    if(arr[0])
    {
        n=m-1;
        arr[0]-=1;
        for(i=0;i<10;i++)
        {
            t*=choose(arr[i],n);
            n-=arr[i];
        }
        return count-t;
    }
    return count;
}

long long countGoodIntegers(int n, int k)
{
    long long a,b,c,d,e;
    long long count=0,curr,temp;
    initialize();
    switch(n)
    {
        case 1:
            return 9/k;
            break;
        case 2:
            for(a=1;a<10;a++)
            {
                temp=a*11;
                if(temp%k==0)
                {
                    count+=rearrange(temp);
                }
            }
            break;
        case 3:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    temp=a*101+b*10;
                    if(temp%k==0)
                    {
                        count+=rearrange(temp);
                    }
                }
            }
            break;
        case 4:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    temp=a*1001+b*110;
                    if(temp%k==0)
                    {
                        count+=rearrange(temp);
                    }
                }
            }
            break;
        case 5:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        temp=a*10001+b*1010+c*100;
                        if(temp%k==0)
                        {
                            count+=rearrange(temp);
                        }
                    }
                }
            }
            break;
        case 6:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        temp=a*100001+b*10010+c*1100;
                        if(temp%k==0)
                        {
                            count+=rearrange(temp);
                        }
                    }
                }
            }
            break;
        case 7:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        for(d=0;d<10;d++)
                        {
                            temp=a*1000001+b*100010+c*10100+d*1000;
                            if(temp%k==0)
                            {
                                count+=rearrange(temp);
                            }
                        }
                    }
                }
            }
            break;
        case 8:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        for(d=0;d<10;d++)
                        {
                            temp=a*10000001+b*1000010+c*100100+d*11000;
                            if(temp%k==0)
                            {
                                count+=rearrange(temp);
                            }
                        }
                    }
                }
            }
            break;
        case 9:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        for(d=0;d<10;d++)
                        {
                            for(e=0;e<10;e++)
                            {
                                temp=a*100000001+b*10000010+c*1000100+d*101000+e*10000;
                                if(temp%k==0)
                                {
                                    count+=rearrange(temp);
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 10:
            for(a=1;a<10;a++)
            {
                for(b=0;b<10;b++)
                {
                    for(c=0;c<10;c++)
                    {
                        for(d=0;d<10;d++)
                        {
                            for(e=0;e<10;e++)
                            {
                                temp=a*1000000001+b*100000010+c*10000100+d*1001000+e*110000;
                                if(temp%k==0)
                                {
                                    count+=rearrange(temp);
                                }
                            }
                        }
                    }
                }
            }
            break;
    }
    clear();
    return count;
}
