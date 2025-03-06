#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* queue=NULL;

void enqueue(struct ListNode* prev)
{
    struct ListNode* temp=prev->next->next;
    prev->next->next=queue;
    queue=prev->next;
    prev->next=temp;
}

struct ListNode* find_tail(void)
{
    if(queue==NULL)
    {
        return NULL;
    }
    else
    {
        struct ListNode* temp=queue;
        while(temp->next)
        {
            temp=temp->next;
        }
        return temp;
    }
}

void pop(struct ListNode* prev)
{
    struct ListNode* tail=find_tail();
    tail->next=prev->next;
    prev->next=queue;
    queue=NULL;
}

struct ListNode* swapPairs(struct ListNode* head)
{
    int i,f=1,k=2;
    struct ListNode pre={};
    pre.next=head;
    struct ListNode* temp=&pre;
    struct ListNode* prev=&pre;
    
    while(1)
    {
        for(i=0;i<k;i++)
        {
            if(temp->next==NULL)
            {
                f=0;
                break;
            }
            temp=temp->next;
        }
        if(f==0)
        {
            break;
        }
        for(i=0;i<k;i++)
        {
            enqueue(prev);
        }
        pop(prev);
        for(i=0;i<k;i++)
        {
            prev=prev->next;
        }
        temp=prev;
    }
    return pre.next;
}
