#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head)
{
    if (head == NULL)
    {
        return false;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (1)
    {
        if (fast->next == NULL || fast->next->next == NULL)
        {
            break;
        }
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
        slow = slow->next;
    }
    return false;
}
