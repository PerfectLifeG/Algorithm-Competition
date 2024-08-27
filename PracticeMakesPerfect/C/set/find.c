#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Set
{
    int data;
    int parent;
};

int find(struct Set s[],int a){
    int i = 0;
    for ( ; i < maxsize&&s[i].data!=a; i++);
    if(i==maxsize)return -1;
    for (; s[i].parent>=0; i=s[i].parent);
    return i;
}
int maxsize; 
int main()
{ 

    return 0;
}