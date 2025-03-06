#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeKLists(struct ListNode** lists,int listsSize)
{
    struct ListNode head={};
    struct ListNode* tail=&head;
    int f=1,i,position=0,min;
    while(1)
    {
        f=0;
        for(i=0;i<listsSize;i++)
        {
            if(lists[i])
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            break;
        }
        min=100000;
        for(i=0;i<listsSize;i++)
        {
            if(lists[i]&&lists[i]->val<min)
            {
                min=lists[i]->val;
                position=i;
            }
        }
        tail->next=lists[position];
        tail=tail->next;
        lists[position]=lists[position]->next;
    }
    return head.next;
}
