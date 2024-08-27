#include<stdio.h>
#include<stdlib.h>
typedef struct Stack* stack;
struct Stack
{
    int data;
    stack next;
};
int pop(stack head);
void push(stack head,int x);

int main()
{
    stack s1,s2; //初始化
    s1=(stack)malloc(sizeof(struct Stack));
    s1->next=NULL;
    s2=(stack)malloc(sizeof(struct Stack));
    s2->next=NULL;
    int n,a,x1,x2,ret;char b;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        push(s1,a);
    }
    getchar();
    for (int i = 0; i < n-1; i++)
    {
        scanf("%c",&b);
        getchar();
        push(s2,b);
    }

    while (s1->next!=NULL||s2->next!=NULL)
    {
        x1=pop(s1);
        x2=pop(s1);
        b=pop(s2);
        switch (b)
        {
        case '/':if(x1==0)
        {
            printf("ERROR: %d/0",x2);
            return 0;
        }else{
            ret=x2/x1;
            push(s1,ret);
            }
        break;
        case '*':ret=x2*x1;push(s1,ret);break;
        case '-':ret=x2-x1;push(s1,ret);break;
        case '+':ret=x2+x1;push(s1,ret);break;
        }
    }
    printf("%d",ret);
    return 0;
}

int pop(stack head)  //出栈必须返回head
{
    stack p;int a;
    if (head->next==NULL)
    {
        return NULL;
    }else{
        p=head->next;
        a=p->data;
        head->next=p->next;
        free(p);  //必须用p
        return a;
    }
}

void push(stack head,int a)
{
    stack p;
    p=(stack)malloc(sizeof(struct Stack));
    p->data=a;
    p->next=head->next;
    head->next=p;
}