#include<stdio.h>
#include<stdlib.h>
typedef struct Stack* stack;
struct Stack
{
    int data;
    stack next;
};
void pop(stack head);
void push(stack head,int x);

int main()
{
    stack head;  //初始化
    head=(stack)malloc(sizeof(struct Stack));
    head->next=NULL;
    push(head,10);
    push(head,20);
    pop(head);
    return 0;
}

void pop(stack head)  //出栈必须返回head
{
    stack p;
    if (head->next==NULL)
    {
        return ;
    }else{
        p=head->next;
        head->next=(head->next)->next;
        free(p);  //必须用p
    }
}

void push(stack head,int x)
{
    stack p;
    p=(stack)malloc(sizeof(struct Stack));
    p->data=x;
    p->next=head->next;
    head->next=p;
}