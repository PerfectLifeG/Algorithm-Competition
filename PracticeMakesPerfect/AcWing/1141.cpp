#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m;
struct Edge{
    int a;
    int b;
    int c;
    bool operator<(const Edge e)const{
        return c<e.c;
    }
}edge[N];
int root[N];
int g[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    root[ra]=rb;
}
int sum;
void kruskal(){
    sort(edge,edge+m);
    for(int i=0;i<n;i++)root[i]=i;
    for(int i=0;i<m;i++){
        auto t=edge[i];
        if(find(t.a)!=find(t.b)){
            merge(t.a,t.b);
            sum+=t.c;
        }
    }
}
int main(){
    int s=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
        s+=c;
    }
    kruskal();
    cout<<s-sum;
    return 0;
}