#include<bits/stdc++.h>
using namespace std;
int post[100];int in[100];
struct tree
{
    int data;
    tree* left;
    tree* right;
};
tree* build(int root,int start ,int end){
    if(start>end)return NULL;//不能等于
    int i=start;
    while (i<end&&post[root]!=in[i])i++;//只要start<end，一定能找到
    tree* t=new tree;
    t->data=post[root];
    t->right=build(root-1,i+1,end);
    t->left=build(root+i-end-1,start,i-1);
    return t;
}
vector<int>r;vector<int>l;
void layer(tree* t){
    queue<tree*>q;
    q.push(t);
    int start=0;int end=1;
    while (!q.empty())
    {
        tree* temp=q.front();
        q.pop();
        if(start==0)l.push_back(temp->data);
        start++;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        if(start==end){
            r.push_back(temp->data);
            end=q.size();
            start=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    tree* t=new tree;
    t=build(n-1,0,n-1);
    layer(t);

    cout<<"R:";
    for (auto it:r)
    {
        cout<<" "<<it;
    }
    cout<<endl;
    cout<<"L:";
    for (auto it:l)
    {
        cout<<" "<<it;
    }
    

    return 0;
}