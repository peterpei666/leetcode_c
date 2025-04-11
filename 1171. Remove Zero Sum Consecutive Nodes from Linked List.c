#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeZeroSumSublists(struct ListNode* head)
{
    int node=0,i,j,sum;
    struct ListNode* cur = NULL;
    struct ListNode* next;
    struct ListNode* list[1000];
    int value[1000];
    bool valid[1000];
    memset(valid,false,1000);
    while(head)
    {
        list[node]=head;
        value[node]=head->val;
        node++;
        head=head->next;
    }
    memset(valid,true,node);
    for(i=node-1;i>=0;i--)
    {
        sum=0;
        for(j=i;j<node;j++)
        {
            if(valid[j])
            {
                sum+=value[j];
            }
            if(sum==0)
            {
                memset(valid+i,false,j-i+1);
            }
        }
    }
    head=NULL;
    for(i=0;i<node;i++)
    {
        if(valid[i]==false)
        {
            continue;
        }
        if(head==NULL)
        {
            head=list[i];
            cur=list[i];
        }
        else
        {
            cur->next=list[i];
            cur=list[i];
        }
    }
    if(cur)
    {
        cur->next=NULL;
    }
    return head;
}
