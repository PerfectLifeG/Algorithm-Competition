#include<stdio.h>
typedef struct Quene* quene;
struct Quene
{
    int data[5];
    int front;
    int rear;
};
void add(quene q,int a);
int delete(quene q);
int main()
{
    return 0;
}
void add(quene q,int a){
    if ((q->rear+1)%5==q->front)//判断满
    {
        return;
    }
    q->rear=(q->rear+1)%5;
    q->data[q->rear]=a;
}

int delete(quene q){
    if (q->front==q->rear)//判断空
    {
        return 0;
    }
    q->front=(q->front+1)%5;
    return q->data[q->front];
}