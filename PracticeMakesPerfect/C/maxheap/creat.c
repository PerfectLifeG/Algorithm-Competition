#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Heap* heap;
struct Heap
{
    int* arr;
    int size;//当前元素
    int cap;//最大容量
};
heap creat(int maxsize){
    heap h=malloc(sizeof(struct Heap));
    h->arr=malloc((maxsize+1)*sizeof(int));
    h->size=0;
    h->cap=maxsize;
    h->arr[0]=maxdata;//哨兵
}
int main()
{
    
    return 0;
}