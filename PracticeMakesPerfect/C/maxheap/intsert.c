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
void intsert(heap h,int a){
    int i;
    if(isfull(h)){
        printf("已满");
        return;
    }
    i= ++(h->size); //将a放到size+1的位置，相当于i=size+1;size++;
    for ( ; h->arr[i/2]<a&&i>1; i/=2)//如果没有哨兵  哨兵是比所有的值包括插入的值都大                                 
    {                                  //推荐有哨兵
        h->arr[i] = h->arr[i/2];     
    }
    h->arr[i]=a;
    
}
int main()
{
    
    return 0;
}