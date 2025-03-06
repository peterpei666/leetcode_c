#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1,struct ListNode* list2)
{
    struct ListNode head={};
    struct ListNode* tail=&head;
    if(list1==NULL&&list2==NULL)
    {
        return NULL;
    }
    if(list1==NULL)
    {
        return list2;
    }
    if(list2==NULL)
    {
        return list1;
    }
    while(list1&&list2)
    {
        if(list1->val>list2->val)
        {
            tail->next=list2;
            list2=list2->next;
        }
        else
        {
            tail->next=list1;
            list1=list1->next;
        }
        tail=tail->next;
    }
    tail->next=list1?list1:list2;
    return head.next;
}
