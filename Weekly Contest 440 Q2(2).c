#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int num;
} node;

int compare(const void* p1, const void* p2)
{
    node* a=(node*)p1;
    node* b=(node*)p2;
    return a->num-b->num;
}

int compare1(const void* p1, const void* p2)
{
    long long* a=(long long*)p1;
    long long* b=(long long*)p2;
    return *a>*b;
}

// 计算最大和
long long* findMaxSum(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
{
    int i;
    long long sum=0;
    long long* ans=(long long*)malloc(nums1Size*sizeof(long long));
    long long* min=(long long*)malloc(k*sizeof(long long));
    node* list=(node*)malloc(nums1Size*sizeof(node));
    for(i=0;i<nums1Size;i++)
    {
        list[i].id=i;
        list[i].num=nums1[i];
    }
    qsort(list,nums1Size,sizeof(node),compare);
    ans[list[0].id]=0;
    
    for(i=1;i<=k;i++)
    {
        sum+=nums2[list[i-1].id];
        min[i-1]=nums2[list[i-1].id];
        if(list[i].num>list[i-1].num)
        {
            ans[list[i].id]=sum;
        }
        else
        {
            ans[list[i].id]=ans[list[i-1].id];
        }
    }
    qsort(min,k,sizeof(long long),compare1);
    for(i=k+1;i<nums1Size;i++)
    {
        if(nums2[list[i-1].id]>min[0])
        {
            sum-=min[0];
            sum+=nums2[list[i-1].id];
            min[0]=nums2[list[i-1].id];
            qsort(min,k,sizeof(long long),compare1);
        }
        if(list[i].num>list[i-1].num)
        {
            ans[list[i].id]=sum;
        }
        else
        {
            ans[list[i].id]=ans[list[i-1].id];
        }
    }
    *returnSize=nums1Size;
    return ans;
}
