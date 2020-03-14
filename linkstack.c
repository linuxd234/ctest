#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
    char c;
    struct linknode *next;
}linkStack,stackNode;

int main()//输入10个字符入栈，注意enter、space 也算字符，不作为输入分隔符，同时enter有提交的作用
{   
    printf("input 10 char :\n");
    char c;
    scanf("%c",&c);
    linkStack *top=(linkStack *)malloc(sizeof(linkStack));
    top->c=c;
    top->next=NULL;
    //push构造链栈
    for (int i = 0; i < 9; i++)
    {
        char c;
        scanf("%c",&c);
        stackNode *stacknode=(stackNode *)malloc(sizeof(stackNode));
        stacknode->c=c;
        stacknode->next=top;
        top=stacknode;
    }
    //pop输出
    while(top){
        stackNode *p=top;
        top=top->next;
        printf("%c  ",p->c);
        free(p);
    }
    
    return 0;
}
