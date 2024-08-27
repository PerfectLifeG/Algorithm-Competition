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
tree find(int a,tree t);
int main()
{
    
    return 0;
}
tree find(int a,tree t){  //尾递归法   效率不高
    if(!t) return NULL;
    if(a<t->data){
        t= find(a,t->left);  //这个return 没想到啊 学艺不精
    }
    else if(a>t->right){
        t= find(a,t->right);
    }
    else 
        return t;
}

tree find(int a,tree t){ //while循环 
    while (t)
    {   
        if(a<t->data)  t=t->left;
        else if(a>t->data)  t=t->right;
        else return t;
    }   
    return NULL;
}