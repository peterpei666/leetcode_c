#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    int cnt=1;
    struct ListNode* temp=head;
    while(temp->next)
    {
        cnt++;
        temp=temp->next;
    }
    k%=cnt;
    if(k==0)
    {
        return head;
    }
    temp->next=head;
    k=cnt-k-1;
    temp=head;
    while(k)
    {
        temp=temp->next;
        k--;
    }
    head=temp->next;
    temp->next=NULL;
    return head;
}
