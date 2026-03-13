#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
 
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = head;
    while (cur && cur->next)
    {
        if (cur->next->val >= cur->val)
        {
            cur = cur->next;
        }
        else
        {
            struct ListNode* temp = cur->next;
            cur->next = temp->next;
            struct ListNode* pre = &dummy;
            while (pre->next->val < temp->val)
            {
                pre = pre->next;
            }
            temp->next = pre->next;
            pre->next = temp;
        }
    }
    return dummy.next;
}
