#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* stk = NULL;
    while (head)
    {
        struct ListNode* temp = head->next;
        head->next = stk;
        stk = head;
        head = temp;
    }
    return stk;
}
