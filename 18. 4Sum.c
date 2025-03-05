#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int arr[4];
    struct node* next;
} node;

int hash_func(int a,int b,int c,int d)
{
    int ret=0;
    ret+=a%10083;
    ret+=b%10083;
    ret+=c%10083;
    ret+=d%10083;
    return (ret%10083+10083)%10083;
}

node* hash_table[10083]={NULL};

node* create(int a,int b,int c,int d)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->arr[0]=a;
    newnode->arr[1]=b;
    newnode->arr[2]=c;
    newnode->arr[3]=d;
    newnode->next=NULL;
    return newnode;
}

void insert(int a,int b,int c,int d)
{
    node* newnode=create(a,b,c,d);
    int hash=hash_func(a,b,c,d);
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

int search(int a,int b,int c,int d)
{
    int hash=hash_func(a,b,c,d);
    node* temp=hash_table[hash];
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        while(temp)
        {
            if(temp->arr[0]==a&&temp->arr[1]==b&&temp->arr[2]==c&&temp->arr[3]==d)
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

int** fourSum(int* nums,int numSize,int target,int* returnSize,int** returnColumnSizes)
{
    int capacity=10,count=0,i,j;
    long long sum;
    int** arr=(int**)malloc(capacity*sizeof(int*));
    int left;
    int right;
    qsort(nums,numSize,sizeof(int),compare);
    for(i=0;i<numSize-3;i++)
    {
        for(j=i+1;j<numSize-2;j++)
        {
            left=j+1;
            right=numSize-1;
            if((nums[i]+nums[j])>target/2)
            {
                break;
            }
            while(left<right)
            {
                sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[left]+(long long)nums[right]-(long long)target;
                if(sum>0)
                {
                    right--;
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    if(search(nums[i],nums[j],nums[left],nums[right])==0)
                    {
                        insert(nums[i],nums[j],nums[left],nums[right]);
                        if(count>=capacity-1)
                        {
                            capacity+=10;
                            arr=(int**)realloc(arr,capacity*sizeof(int*));
                        }
                        int* row=(int*)malloc(4*sizeof(int));
                        row[0]=nums[i];
                        row[1]=nums[j];
                        row[2]=nums[left];
                        row[3]=nums[right];
                        arr[count]=row;
                        count++;
                    }
                    left++;
                    right--;
                }
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
            (*returnColumnSizes)[i]=4;
        }
    }
    clear();
    return arr;
}


