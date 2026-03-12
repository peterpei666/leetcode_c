#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head)
{
    if (!head || !head->next || !head->next->next)
    {
        return;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = NULL;
    struct ListNode* stk = NULL;
    while (temp)
    {
        struct ListNode* t = temp->next;
        temp->next = stk;
        stk = temp;
        temp = t;
    }
    temp = head;
    while (stk)
    {
        struct ListNode* t = temp->next;
        temp->next = stk;
        stk = stk->next;
        temp->next->next = t;
        temp = t;
    }
}
