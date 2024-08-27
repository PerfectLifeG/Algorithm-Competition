#include<bits/stdc++.h>
using namespace std;
int post[1100];
int in[1100];
struct Node{
    Node* left;
    Node* right;
};
Node* build(int root,int l,int r){
    if(l>r)return NULL;
    int i=l;
    while(i<=r&&post[root]!=in[i])i++;
    Node* t=new Node();
    t->left=build(root-1-r+i,l,i-1);
    t->right=build(root-1,i+1,r);
    return t;
};
int cl,cr;
void dfs(Node* t){
    if(t->left){
        dfs(t->left);
    }
    if(t->right){
        dfs(t->right);
    }
    if(t->left&&t->right==NULL){
        cl++;
    }
    if(t->left==NULL&&t->right){
        cr++;
    }
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    Node* t=new Node();
    t=build(n-1,0,n-1);
    dfs(t);
    printf("%d = %d - %d",cl-cr,cl,cr);
}
