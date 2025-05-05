#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    int temp=1000;
    struct ListNode* cur=head;
    struct ListNode* t;
    while(cur)
    {
        if(temp!=cur->val)
        {
            temp=cur->val;
        }
        t=cur->next;
        while(t&&t->val==temp)
        {
            t=t->next;
        }
        cur->next=t;
        cur=t;
    }
    return head;
}
