#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef struct Tree* tree;
struct Tree{
    tree left=NULL;
    tree right=NULL;
    int data;
}node[N];
tree build(tree t,int x){
    if(t->)return t;
    else if(){
        tree temp=new Tree;
        t->left=build(,x);
    }
    else t->right=build(,x);
}
queue<int>q;
int book[N],num[N];
int mx;
void bfs(){
    q.push(0);
    book[0]=1;num[0]=1;
    while(q.size()){
        auto t=q.front();
        q.pop();
        mx=max(mx,num[t]);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        build(0,a);
    }
    bfs();
    int ans=0;
    if(mx<=2)cout<<n;
    else{
    for(int i=0;i<n;i++){
        if(num[i]==mx-1||num[i]==mx-2)ans++;
    }
    cout<<ans;}
    return 0;
}