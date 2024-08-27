#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Tree* tree;
struct Tree
{
    tree left;
    tree right;
    int data;
};
tree insert(int a,tree t);
int main()
{
    
    return 0;
}

tree insert(int a,tree t){ 
    if(!t){
        t=(tree)malloc(sizeof(struct Tree));
        t->right=t->left=NULL;
        t->data=a;
    }else
        if(a<t->data)
        t->left=insert(a,t->left);
        else if(a>t->data)
        t->right=insert(a,t->right);
    return t;
}