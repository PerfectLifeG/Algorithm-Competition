#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,m,c;
struct Edge{
    int a,b,c;
}edge[2*N];
bool cmp(Edge &e1,Edge &e2){
    return e1.c<e2.c;
}
int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    root[find(a)]=find(b);
}
vector<int>v;
void kruskal(){
    sort(edge,edge+m,cmp);
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=0;i<m;i++){
        int a=edge[i].a;int b=edge[i].b;
        if(find(a)!=find(b)){
            v.emplace_back(edge[i].c);
            merge(a,b);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>c;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>edge[i].a>>edge[i].b>>edge[i].c;
    }
    kruskal();
    int cnt=1;
    for(int i=v.size()-1;i>=0;i--){
        if(c-cnt*v[i]>=0)c-=cnt*v[i];
        else {cout<<v[i];break;}
        cnt++;
    }
    return 0;
}