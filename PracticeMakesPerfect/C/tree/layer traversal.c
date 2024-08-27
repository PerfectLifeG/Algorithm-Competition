#include<stdio.h>
#include<stdlib.h>
typedef struct Tree* tree;
typedef struct Node* node;
struct Tree
{
    int data;
    tree left;
    tree right;
};
struct Node
{
    tree data;
    node next;
};
typedef struct Queue* queue;
struct Queue
{
    node front;
    node rear;
};
void add(queue q,tree a);
tree delete(queue q);
void layer(tree t);

int main()
{
    
    return 0;
}
void add(queue q,tree a){
    node p;
    p=(node)malloc(sizeof(struct Node));
    p->data=a;
    if (q->front==NULL)
    {
        q->front=p;
    }
    q->rear=p;
}
tree delete(queue q){
    tree a;node p;
    if (q->front==NULL)
    {
        return 0;
    }
    p=q->front;
    a=p->data;
    if (p->next==NULL)
    {
        q->front=q->rear=NULL;
    }
    free(p);
    q->front=p->next;
    return a;
}
void layer(tree t){   //注意要初始化队列
    queue q;
    q->front=NULL;
    q->rear=NULL;
    if(t)
    { 
        add(q,t);
        while (q->front)
        {
            t=delete(q);
            printf("%d",t->data);
            if (t->left)
            {
                add(q,t->left);
            }
            if (t->right)
            {
                add(q,t->right);
            }
        }
    }
}