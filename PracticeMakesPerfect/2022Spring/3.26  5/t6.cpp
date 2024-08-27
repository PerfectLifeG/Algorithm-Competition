#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
int l; int r;
class tree
{
    public:
    int data;
    tree* left;
    tree* right;
    tree(){
        left=NULL;
        right=NULL;
    }
};
int first;int flag=1;
tree* build(tree* t){
    int a;
    scanf("%d",&a);
    if(a==0){t->data=0;return NULL;}
    else{
        t->data=a;
        tree* temp1=new tree;
        t->left=build(temp1);
        tree* temp2=new tree;
        t->right=build(temp2);
    }
    return t;
}
void left(tree* t){
    if(flag==0)return;
    tree* temp=t;
    if(t==NULL)return;
    if(t->left==NULL&&t->right==NULL){
        l=temp->data;
        flag=0;
        return;
    }
    left(t->left);
    if(t->data!=first)
    left(t->right);
}
void right(tree* t){
    if(flag==0)return;
    tree* temp=t;
    if(t==NULL)return;
    if(t->left==NULL&&t->right==NULL){
        r=temp->data;
        flag=0;
        return;
    }
    right(t->right);
    if(t->data!=first)
    right(t->left);
}
int main()
{
    tree* t=new tree;t->left=NULL;t->right=NULL;
    t=build(t);
    first=t->data;
    left(t);
    flag=1;
    right(t);
    cout<<abs(r-l);
    return 0;
}