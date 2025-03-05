#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int id;
    struct node* next;
} node;

node* top=NULL;

node* create(char c)
{
    node* newnode=(node*)malloc(sizeof(node));
    switch(c)
    {
        case '(':
        {
            newnode->id=1;
            break;
        }
        case '[':
        {
            newnode->id=2;
            break;
        }
        case '{':
        {
            newnode->id=3;
            break;
        }
        default:
            newnode->id=0;
            break;
    }
    newnode->next=NULL;
    return newnode;
}

void enqueue(char c)
{
    node* newnode=create(c);
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=(struct node*)top;
        top=newnode;
    }
}

int pop(void)
{
    if(top==NULL)
    {
        return 1;
    }
    node* temp=(node*)top->next;
    free(top);
    top=temp;
    return 0;
}

int compare(char c)
{
    if(top==NULL)
    {
        return 0;
    }
    switch(c)
    {
        case ')':
            if(top->id==1)
            {
                return 1;
            }
            break;
        case ']':
            if(top->id==2)
            {
                return 1;
            }
            break;
        case '}':
            if(top->id==3)
            {
                return 1;
            }
            break;
    }
    return 0;
}

bool isValid(char* s)
{
    int i=0,f=0,valid;
    while(*(s+i)!='\0')
    {
        if(compare(*(s+i)))
        {
            f=pop();
            if(f)
            {
                return false;
            }
        }
        else
        {
            enqueue(*(s+i));
        }
        i++;
    }
    valid=top?0:1;
    while(top)
    {
        pop();
    }
    if(valid==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
