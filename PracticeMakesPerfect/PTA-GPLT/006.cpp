#include<bits/stdc++.h>
using namespace std;
int post[100];int in[100];
struct tree
{
    int data;
    tree* left;
    tree* right;
};
tree* build(int root,int l,int r){
    if(l>r)return NULL;
    int i=l;
    while (i<r&&post[root]!=in[i])i++;
    tree* t=new tree;
    t->data=post[root];
    t->right=build(root-1,i+1,r);
    t->left=build(root-1-r+i,l,i-1);
    return t;
}
void showlayer(tree* t){
    queue<tree*>q;
    q.push(t);
    while (!q.empty())
    {
        tree* temp=q.front();
        q.pop();
        if(temp==t)
        printf("%d",temp->data);
        else printf(" %d",temp->data);
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    tree* t=new tree;
    t=build(n-1,0,n-1);
    showlayer(t);
    return 0;
}