#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    while (head)
    {
        if (head->val != val)
        {
            temp->next = head;
            temp = head;
        }
        head = head->next;
    }
    temp->next = NULL;
    return dummy.next;
}
