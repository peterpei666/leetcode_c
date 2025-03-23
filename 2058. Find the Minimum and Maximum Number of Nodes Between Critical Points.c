#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
{
    int prev=0,curr=0,next=0,count=0,i=0,capacity=10;
    int* list=(int*)malloc(capacity*sizeof(int));
    int* ans=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    while(head)
    {
        if(i==0)
        {
            prev=head->val;
        }
        else if(i==1)
        {
            curr=head->val;
        }
        else
        {
            next=head->val;
            if((next>curr&&prev>curr)||(next<curr&&prev<curr))
            {
                list[count]=i;
                count++;
                if(count>=capacity-2)
                {
                    capacity+=10;
                    list=(int*)realloc(list,capacity*sizeof(int));
                }
            }
            prev=curr;
            curr=next;
        }
        head=head->next;
        i++;
    }
    if(count<2)
    {
        ans[0]=-1;
        ans[1]=-1;
    }
    else
    {
        ans[1]=list[count-1]-list[0];
        ans[0]=list[1]-list[0];
        for(i=2;i<count;i++)
        {
            if(ans[0]==1)
            {
                break;
            }
            if(ans[0]>list[i]-list[i-1])
            {
                ans[0]=list[i]-list[i-1];
            }
        }
    }
    free(list);
    return ans;
}

