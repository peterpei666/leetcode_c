#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* detectCycle(struct ListNode *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    struct ListNode* p1;
    struct ListNode* p2;
    while(fast->next&&fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            p1=head;
            p2=slow;
            while(p1!=p2)
            {
                p1=p1->next;
                p2=p2->next;
            }
            return p1;
        }
    }
    return NULL;
}
