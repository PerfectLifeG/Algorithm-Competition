#include<stdio.h>
#include<stdlib.h>
typedef struct Stack* stack;
struct Stack
{
    int data;
    stack next;
};
void push(stack head,int x);
int main()
{
    stack head;  //初始化
    head=(stack)malloc(sizeof(struct Stack));
    head->next=NULL;
    push(head,10);
    push(head,20);
    return 0;
}
void push(stack head,int x)
{
    stack p;
    p=(stack)malloc(sizeof(struct Stack));
    p->data=x;
    p->next=head->next;
    head->next=p;
}