#include<stdio.h>
#include<stdlib.h>
typedef struct Stack* stack;
struct Stack
{
    tree data;
    stack next;
};
void push(stack head,tree t);
tree pop(stack head); 

typedef struct Tree* tree;
struct Tree
{
    int data;
    tree left;
    tree right;
};
void non(tree t);

int main()
{
    stack head;
    head=(stack)malloc(sizeof(struct Stack));
    head->next=NULL;
    push(head,5);
    push(head,10);
    pop(head);
    return 0;
}
void non(tree t){
    stack s;
    s=(stack)malloc(sizeof(struct Stack));
    s->next=NULL;
    while (t||s->next)   //条件是缺一不可
    {    
        while (t)
        {
            push(s,t);
            t=t->left;           
        }
        if (s->next)
        {
            t=pop(s);                           //少了这句
            printf("%d",t->data);
            t=t->right;
        }
    }
}

void push(stack head,tree a){
    stack p;
    p=(stack)malloc(sizeof(struct Stack));
    p->data=a;
    p->next=head->next;
    head->next=p;
}

tree pop(stack head){
    stack p;tree a;
    if (head->next==NULL)
    {
        return 0;
    }else{
        p=head->next;
        a=p->data;
        head->next=p->next;
        free(p);
        return a;
    }
}