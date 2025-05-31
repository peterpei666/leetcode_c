#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* queue;

inline void enqueue(struct ListNode* temp)
{
    temp->next=queue;
    queue=temp;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    if(left==right)
    {
        return head;
    }
    int i;
    struct ListNode start={};
    queue=NULL;
    start.next=head;
    struct ListNode* prev=&start;
    struct ListNode* temp;
    struct ListNode* next=NULL;
    for(i=1;i<left;i++)
    {
        prev=prev->next;
    }
    temp=prev->next;
    for(i=left;i<=right;i++)
    {
        next=temp->next;
        enqueue(temp);
        temp=next;
    }
    prev->next=queue;
    temp=queue;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=next;
    return start.next;
}
