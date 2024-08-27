#include<stdio.h>
typedef struct stack* s;
struct stack
{
    int data[10];
    int top;
};
void pop(s p);
int main()
{
    struct stack S;
    s p=&S;
    p->top=-1;
    pop(p);
    return 0;
}
void pop(s p){
    if (p->top==-1)   //先判断堆栈是否空
    {
        return;
    }else {
        printf("%d",p->data[(p->top)--]);
    }
}