#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    int i;
    struct ListNode* ret=list1;
    struct ListNode* temp;
    struct ListNode* prev;
    for(i=1;i<a;i++)
    {
        list1=list1->next;
    }
    temp=list1->next;
    for(i=a;i<=b;i++)
    {
        prev=temp;
        temp=temp->next;
        free(prev);
    }
    list1->next=list2;
    while(list2->next)
    {
        list2=list2->next;
    }
    list2->next=temp;
    return ret;
}
