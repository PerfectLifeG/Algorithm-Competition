#include<bits/stdc++.h>
using namespace std;
const int N=51;
int book[N];
int st[N];
int g[N][N];int n;
int dfs(int t){
    if(book[t])return 0;
    if(book[0]==n*n-1)return 1;
    book[t]=1;
    book[0]++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
            g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(st[i])continue;
        st[i]=1;
        g[i][j];
        if(dfs(i))return 1;
        st[i]=0;
    }
    return 1;
}
int main(){
    int t;cin>>t;
    while(t--){
        scanf("%d",&n);
        dfs();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",g[i][j]);
            }
            puts("");
        }
    }
    return 0;
}