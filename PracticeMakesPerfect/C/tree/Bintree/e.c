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
int main()
{
    tree t,p,q;
    p=(tree)malloc(sizeof(struct Tree));
    t=(tree)malloc(sizeof(struct Tree));
    q=(tree)malloc(sizeof(struct Tree));
    t->left=p;
    t->right=q;
    p=NULL;
    int a;
    return 0;
}
