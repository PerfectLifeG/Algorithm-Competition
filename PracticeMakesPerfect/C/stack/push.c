#include<stdio.h>
typedef struct stack* s;
struct stack
{
    int data[10];
    int top;
};
void push(s p,int x);
int main()
{
    struct stack S;
    s p=&S;
    p->top=-1;
    push(p,10);
    return 0;
}
void push(s p,int x){
    if (p->top==9)   //先判断堆栈是否满
    {
        return;
    }else
    p->data[++(p->top)]=x;
}