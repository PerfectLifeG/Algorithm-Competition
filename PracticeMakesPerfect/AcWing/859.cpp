#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,m;
int sum,cnt;
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
    int ra=find(a);
    int rb=find(b);
    if(ra!=rb)root[ra]=rb;
}
void kruskal(){
    sort(edge,edge+m,cmp);
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=0;i<m;i++){
        int a=edge[i].a;int b=edge[i].b;
        if(find(a)!=find(b)){
            cnt++;
            sum+=edge[i].c;
            merge(a,b);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
    }
    kruskal();
    if(cnt!=n-1)cout<<"impossible";
    else cout<<sum;
    return 0;
}