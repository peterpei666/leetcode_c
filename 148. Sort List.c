#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeSort(struct ListNode* head, int sz)
{
    if (sz == 1)
    {
        return head;
    }
    int mid = sz / 2;
    struct ListNode* t = head;
    for (int i = 0; i < mid - 1; i++)
    {
        t = t->next;
    }
    struct ListNode* t2 = mergeSort(t->next, sz - mid);
    t->next = NULL;
    struct ListNode* t1 = mergeSort(head, mid);
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    while (t1 && t2)
    {
        if (t1->val < t2->val)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    temp->next = t1 ? t1 : t2;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head)
{
    int sz = 0;
    struct ListNode* temp = head;
    while (temp)
    {
        sz++;
        temp = temp->next;
    }
    if (sz == 0)
    {
        return NULL;
    }
    return mergeSort(head, sz);
}
