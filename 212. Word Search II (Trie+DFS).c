#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET 26

typedef struct node
{
    struct node* children[ALPHABET];
    char* word;
} node;

int direction[4][2]={-1,0,1,0,0,-1,0,1};

node* create(void)
{
    int i;
    node* newnode=(node*)malloc(sizeof(node));
    for(i=0;i<ALPHABET;i++)
    {
        newnode->children[i]=NULL;
    }
    newnode->word=NULL;
    return newnode;
}

void insert(node* root,char* word)
{
    node* temp=root;
    int index,i=0;
    while(*(word+i)!='\0')
    {
        index=*(word+i)-'a';
        if(temp->children[index]==NULL)
        {
            temp->children[index]=create();
        }
        temp=temp->children[index];
        i++;
    }
    temp->word=strdup(word);
}

void dfs(char** board,int boardSize,int* boardColSize,int i,int j,node* n,char** result,int* count)
{
    char c=board[i][j];
    int d,row,col;
    if(c=='*'||n->children[c-'a']==NULL)
    {
        return;
    }
    n=n->children[c-'a'];
    if(n->word)
    {
        result[*count]=strdup(n->word);
        (*count)++;
        n->word=NULL;
    }
    board[i][j]='*';
    for(d=0;d<4;d++)
    {
        row=i+direction[d][0];
        col=j+direction[d][1];
        if(row>=0&&row<boardSize&&col>=0&&col<boardColSize[row])
        {
            dfs(board,boardSize,boardColSize,row,col,n,result,count);
        }
    }
    board[i][j]=c;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize)
{
    node* root=create();
    int i,j,count=0;
    char** result=(char**)malloc(sizeof(char*)*wordsSize);
    for(i=0;i<wordsSize;i++)
    {
        insert(root,words[i]);
    }
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[i];j++)
        {
            dfs(board,boardSize,boardColSize,i,j,root,result,&count);
        }
    }
    *returnSize=count;
    return result;
}
