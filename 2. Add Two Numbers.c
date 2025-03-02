#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* create(int data)
{
    struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val=data;
    newnode->next=NULL;
    return newnode;
}

void insert(struct ListNode** root,int data)
{
    struct ListNode* temp=*root;
    struct ListNode* newnode=create(data%10);
    if(temp==NULL)
    {
        *root=newnode;
    }
    else
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2)
{
    struct ListNode* root=NULL;
    int f=0,m;
    while(l1||l2)
    {
        m=0;
        if(l1)
        {
            m+=l1->val;
            l1=l1->next;
        }
        if(l2)
        {
            m+=l2->val;
            l2=l2->next;
        }
        m+=f;
        f=m/10;
        insert(&root,m%10);
    }
    if(f)
    {
        insert(&root,f);
    }
    return root;
}
