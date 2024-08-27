#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Set
{
    int data;
    int parent;
};

int _union(struct Set s[],int a,int b){
    int root1=find(s,a);
    int root2=find(s,b);
    if(root1!=root2){
        if(-s[root1].parent>=-s[root2].parent)
        s[root2].parent=root1;
        else s[root1].parent=root2;
    }
}
int maxsize; 
int main()
{ 

    return 0;
}