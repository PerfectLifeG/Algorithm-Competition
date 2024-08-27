#include<bits/stdc++.h>
using namespace std;
const int N=100;
struct Node{
    int x=0;
    Node* l=NULL;
    Node* r=NULL;
    bool operator<(const Node n)const{
        return x<n.x;
    }
}node[N];
unordered_map<char,int>mp;
priority_queue<Node,vector<Node>,less<Node>>p;
int res;
int flag;
void dfs(Node* t,int v){
    if(t==NULL)return;
    if(t->l)dfs(t->l,v+1);
    if(t->r)dfs(t->r,v+1);
    if(!t->l&&!t->r)res+=v*(t->x);
}
Node* build(){
    while(p.size()){
        auto a=p.top();p.pop();
        auto b=p.top();p.pop();
        auto t=a;
        t.x=a.x+b.x;
        t.l=&a;t.r=&b;
        if(p.empty())return &t;
        p.push(t);
    }
}
Node* temp;
void build2(char c,string s){
    Node* t=temp;
    for(int i=0;i<s.size();i++){
        if(s[i]==0){
            if(!t->l){
                auto t2=new Node;
                t->l=t2;
            }
            t=t.l;
            t->x=1;
            if(t->x){flag=0;return;}
        }else if(s[i]==1){
            if(!t->r){
                auto t2=new Node;
                t->r=t2;
            }
            t=&t.r;
            t->x=1;
            if(t->x){flag=0;return;}
        }
    }
    t->x=c;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char c;int a;
        scanf("%c %d",&c,&a);
        mp[c]=a;
        p.push({a});
    }
    dfs(build(),1);
    int m;cin>>m;
    while(m--){
        int sum=0;
        flag=1;
        temp=new Node;
        for(int i=0;i<n;i++){
            char c;string s;
            cin>>c>>s;
            if(flag==0)continue;
            build2(c,s);
            sum+=mp[c]*s.size();
        }
        if(sum!=res)flag=0;
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}