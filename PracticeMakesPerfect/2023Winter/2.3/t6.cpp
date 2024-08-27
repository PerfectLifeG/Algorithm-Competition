#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int n,m,k;
int sum;
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
int kruskal(){
    sort(edge,edge+m,cmp);
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=0;i<m;i++){
        int a=edge[i].a;int b=edge[i].b;
        if(find(a)!=find(b)){
            sum+=edge[i].c;
            merge(a,b);
        }
    }
    return sum;
}
signed main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;m++,j++){
            edge[m].a=i;edge[m].b=j;
            int temp=__gcd(i,j);
            if(j-i<=k)edge[m].c=i*j/temp;
            else edge[m].c=temp;
//             cout<<i<<' '<<j<<' '<<edge[i].c<<endl;;
        }
    }
    cout<<kruskal();
    return 0;
}