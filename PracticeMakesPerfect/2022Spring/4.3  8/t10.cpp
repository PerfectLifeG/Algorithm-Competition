#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
vector<int>r;vector<int>l;
typedef struct Tree* tree;
struct Tree
{
    int data;
    tree left;
    tree right;
};
int post[100];int in[100];
tree build(int root,int start,int end){
    if(start>end)return NULL;
    int i=start;
    while (i<end&&in[i]!=post[root])i++;
    tree t=new Tree;
    t->data=post[root];
    t->right=build(root-1,i+1,end);
    t->left=build(root-1-end+i,start,i-1);
    return t;
}
void layer(tree t){
    queue<tree>q;
    q.push(t);
    int start=0;int end=1;
    while (!q.empty())
    {
        tree temp=q.front();
        q.pop();
        if(start==0)l.push_back(temp->data);
        start++;
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        if(start==end){
            start=0;
            end=q.size();
            r.push_back(temp->data);
        }
    }
    
    
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
        cin>>post[i];   
    }
    tree t=build(n-1,0,n-1);
    layer(t);
    cout<<"R:";
    for (auto it = r.begin(); it!=r.end(); it++)
    {
        cout<<" "<<*it;
    }
    cout<<endl;
    cout<<"L:";
    for (auto it = l.begin(); it!=l.end(); it++)
    {
        cout<<" "<<*it;
    }
    return 0;
}