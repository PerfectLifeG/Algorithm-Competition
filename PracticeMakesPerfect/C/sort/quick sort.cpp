#include<bits\stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void quicksort(int *a,int size){
    int i=1;int j=size-1;
    if(j<i)return ;  //这个不能省啊
    while(i!=j){
        while(a[j]>a[0]&&i<j)
        j--;
        while(a[i]<a[0]&&i<j)
        i++;
        if(i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[0],&a[j]);
    quicksort(&a[0],i);
    quicksort(&a[i+1],size-i-1);
}
int a[10]={6,1,2,7,9,3,4,5,10,8};
int main()
{
   
    quicksort(a,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}