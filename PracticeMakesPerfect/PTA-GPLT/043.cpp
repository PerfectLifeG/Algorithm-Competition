#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
int sum,mx;
int dis[N];int book[N];
int root[N];
int dfs(int s){
    if(root[s]==-1||book[s]==1)return dis[s];
    sum++;
    book[s]=1;
    dis[s] = dfs(root[s])+1;
    return dis[s];
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n ;i++){scanf("%d",&root[i]);};
    while(m--){
        int a;scanf("%d",&a);
        mx=max(mx,dfs(a));
        printf("%d\n",2*sum-mx);
    }
    return 0;
}