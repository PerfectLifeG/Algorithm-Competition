#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,m,rt;
int fa[N][20],depth[N];
struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
}tr[N];
int pre[N],in[N];
Node* tree;
Node* build(int root,int l,int r){
    if(l>r)return NULL;
    int i=l;
    while(i<=r&&pre[root]!=in[i])i++;
    Node* t=new Node;
    t->data=pre[root];
    if(pre[root]==rt)tree=t;
    t->left=build(root+1,l,i-1);
    t->right=build(root+i-l+1,i+1,r);
    return t;
}
void bfs(Node* t){
    memset(depth,-1,sizeof depth);
    queue<Node*>q;
    q.push(t);
    depth[t->data]=1;depth[0]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t->left){
            int a=t->data,b=t->left->data;
            depth[b]=depth[a]+1;
            fa[b][0]=a;
            for(int i=1;i<20;i++){
                fa[b][i]=fa[fa[b][i-1]][i-1];
            }
            q.push(t->left);
        }
        if(t->right){
            int a=t->data,b=t->right->data;
            depth[b]=depth[a]+1;
            fa[b][0]=a;
            for(int i=1;i<20;i++){
                fa[b][i]=fa[fa[b][i-1]][i-1];
            }
            q.push(t->right);
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b])swap(a,b);
    for(int i=19;i>=0;i--){
        if(depth[fa[a][i]]>=depth[b]){
            a=fa[a][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(fa[a][i]!=fa[b][i]){
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>rt;
    for(int i=0;i<n;i++)cin>>pre[i];
    for(int i=0;i<n;i++)cin>>in[i];
    auto t=build(0,0,n-1);
    bfs(t);
    while(m--){
        int a,b;cin>>a>>b;
        int t=lca(a,b);
        cout<<t<<endl;
    }
    return 0;
}