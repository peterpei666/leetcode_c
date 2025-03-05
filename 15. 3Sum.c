#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int arr[3];
    struct node* next;
} node;

int hash_func(int a,int b,int c)
{
    int ret=a*97+b*89+c*83;
    return (ret%10083+10083)%10083;
}

node* hash_table[10083]={NULL};

node* create(int a,int b,int c)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->arr[0]=a;
    newnode->arr[1]=b;
    newnode->arr[2]=c;
    newnode->next=NULL;
    return newnode;
}

void insert(int a,int b,int c)
{
    node* newnode=create(a,b,c);
    int hash=hash_func(a,b,c);
    if(hash_table[hash]==NULL)
    {
        hash_table[hash]=newnode;
    }
    else
    {
        node* temp=hash_table[hash];
        while(temp->next)
        {
            temp=(node*)temp->next;
        }
        temp->next=(struct node*)newnode;
    }
}

int search(int a,int b,int c)
{
    int hash=hash_func(a,b,c);
    node* temp=hash_table[hash];
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        while(temp)
        {
            if(temp->arr[0]==a&&temp->arr[1]==b&&temp->arr[2]==c)
            {
                return 1;
            }
            temp=(node*)temp->next;
        }
        return 0;
    }
}

int compare(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
    for(i=0;i<10083;i++)
    {
        if(hash_table[i]==NULL)
        {
            continue;
        }
        else
        {
            temp=hash_table[i];
            while(temp)
            {
                prev=temp;
                temp=(node*)temp->next;
                free(prev);
            }
            hash_table[i]=NULL;
        }
    }
}

int** threeSum(int* nums,int numSize,int* returnSize,int** returnColumnSizes)
{
    int capacity=10,count=0,i,sum;
    int** arr=(int**)malloc(capacity*sizeof(int*));
    int left;
    int right;
    qsort(nums,numSize,sizeof(int),compare);
    for(i=1;i<numSize-1;i++)
    {
        left=i-1;
        right=i+1;
        while(left>=0&&right<=numSize-1)
        {
            sum=nums[left]+nums[i]+nums[right];
            if(sum<0)
            {
                right++;
            }
            else if(sum>0)
            {
                left--;
            }
            else
            {
                if(search(nums[left],nums[i],nums[right])==0)
                {
                    insert(nums[left],nums[i],nums[right]);
                    if(count>=capacity-1)
                    {
                        capacity+=10;
                        arr=(int**)realloc(arr,capacity*sizeof(int*));
                    }
                    int* row=(int*)malloc(3*sizeof(int));
                    row[0]=nums[left];
                    row[1]=nums[i];
                    row[2]=nums[right];
                    arr[count]=row;
                    count++;
                }
                left--;
                right++;
            }
        }
    }
    *returnSize=count;
    if(count==0)
    {
        *returnColumnSizes=NULL;
    }
    else
    {
        *returnColumnSizes=(int*)malloc(count*sizeof(int));
        for(i=0;i<count;i++)
        {
            (*returnColumnSizes)[i]=3;
        }
    }
    clear();
    return arr;
}


