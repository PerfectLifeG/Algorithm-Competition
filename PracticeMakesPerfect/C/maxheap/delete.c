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
void delete(heap h,int a){
    int i=1,t;
    if(isempty(h)){
        printf("堆空");
        return;
    }
    h->size--;
    t=h->arr[i]=h->arr[h->size];  //这两行可以合并。。。
    while (h->arr[i]<h->arr[2*i]||h->arr[i]<h->arr[2*i+1])
    {
        if(h->arr[2*i]<h->arr[2*i+1])  //通过一个中间变量t最后再赋值，不用一直交换
       {
           
       }else{

       }
    }
    

    return t;
}
int main()
{
    
    return 0;
}