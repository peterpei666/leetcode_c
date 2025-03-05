#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char phone_map[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char* digit_temp;
int digit_size;
char** combinations;
int combinations_size;
char* combination;
int combination_size;

void backtrack(int index)
{
    if(index==digit_size)
    {
        char* temp=(char*)malloc(sizeof(char)*(combination_size+1));
        memcpy(temp,combination,sizeof(char)*(combination_size+1));
        combinations[combinations_size++]=temp;
    }
    else
    {
        int i;
        char digit=digit_temp[index];
        char* letters=phone_map[digit-'0'];
        int len=(int)strlen(letters);
        for(i=0;i<len;i++)
        {
            combination[combination_size]=letters[i];
            combination_size++;
            combination[combination_size]='\0';
            backtrack(index+1);
            combination_size--;
            combination[combination_size]='\0';
        }
    }
}

char** letterCombinations(char* digits,int* returnSize)
{
    combination_size=0;
    combinations_size=0;
    digit_temp=digits;
    digit_size=(int)strlen(digits);
    int num=1,i,d;
    if(digit_size==0)
    {
        *returnSize=0;
        return NULL;
    }
    for(i=0;i<digit_size;i++)
    {
        d=*(digits+i)-'0';
        num*=strlen(phone_map[d]);
    }
    combinations=(char**)malloc(sizeof(char*)*num);
    combination=(char*)malloc(sizeof(char)*(digit_size+1));
    backtrack(0);
    *returnSize=combinations_size;
    free(combination);
    return combinations;
}
