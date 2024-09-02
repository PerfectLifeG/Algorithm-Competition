#include<bits/stdc++.h>
using namespace std;
int pre[30];int in[30];
struct tree
{
    int data;
    tree* left;
    tree* right;
};
tree* build(int root,int l,int r){
    if(l>r)return NULL;
    int i=l;
    while(i<r&&pre[root]!=in[i])i++;
    tree* t=new tree;
    t->data=in[i];
    t->left=build(root+1,l,i-1);
    t->right=build(root+i-l+1,i+1,r);
    return t;
}
void layer(tree* t){
    queue<tree*>q;int flag=0;
    q.push(t);
    while(!q.empty()){
        tree* t=q.front();
        if(flag==0){cout<<t->data;flag=1;}
        else cout<<" "<<t->data;
        q.pop();
        if(t->right){
            q.push(t->right);
        }
        if(t->left){
            q.push(t->left);
        }
    }
    cout<<endl;
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>pre[i];
    }
    tree* t=new tree;
    t=build(0,0,n-1);
    layer(t);
    return 0;
}