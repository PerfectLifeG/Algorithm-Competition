#include<stdio.h>
#include<stdlib.h>
typedef struct Queue* queue;
typedef struct Node* node;
struct Node
{
    int data;
    node next;
};

struct Queue
{
    node front;
    node rear;
};
void add(queue q,int a);
int delete(queue q);

int main()
{
    
    return 0;
}

void add(queue q,int a){//此处要注意判断  队列是否为空
    node p;
    p=(node)malloc(sizeof(struct Node));
    p->data=a;
    if (q->front==NULL)
    {
        q->front=p;
    }
    q->rear=p;
}

int delete(queue q){    //此处要注意判断  队列是否只有一个元素  若不止一个元素 则rear是不动的
    node p;int a;     
    p=q->front;
    if (q->front==NULL)
    {
        return NULL;
    }
    if (q->front==q->rear)
    {
        q->rear=q->front=NULL;
    }
    a=p->data;
    q->front=p->next;
    free(p);
    return(a);
}