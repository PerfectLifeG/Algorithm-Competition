#include<stdio.h>
typedef struct Tree* tree;
struct Tree
{
    int data;
    tree left;
    tree right;
};

void preorder(tree t);

int main()
{
    
    return 0;
}
void preorder(tree t){
    if (t)
    {
        printf("%d",t->data);
        preorder(t->left);       
        preorder(t->right);
    }
}