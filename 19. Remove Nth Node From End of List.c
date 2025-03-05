#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head,int n)
{
    struct ListNode* list[30]={NULL};
    struct ListNode* temp=head;
    int m=0;
    while(temp)
    {
        list[m]=temp;
        temp=temp->next;
        m++;
    }
    if(m==1)
    {
        return NULL;
    }
    if(n==m)
    {
        return list[1];
    }
    else
    {
        list[m-n-1]->next=list[m-n+1];
        return head;
    }
}
