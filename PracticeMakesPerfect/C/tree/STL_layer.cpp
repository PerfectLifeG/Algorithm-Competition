#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
typedef struct Tree* tree;
struct Tree
{
    int data;
    tree left;
    tree right;
};
int mid[10];
int pre[10];
tree build(int root,int start,int end){
    if(start>end)return NULL;
    int i=start;
    while (i<end&&mid[i]!=pre[root])i++;
    tree t=new Tree;
    t->data=pre[root];
    t->left=build(root+1,start,i-1);
    t->right=build(root+1+i-start,i+1,end);
    return t;
}
void layershow(tree t){
    queue<tree>q;
    if(t)q.push(t);
    while (!q.empty())
    {
        tree temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        
    }
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>mid[i];
    }
    tree t=build(0,0,n-1);//恶心到我了
    layershow(t);
    return 0;
}