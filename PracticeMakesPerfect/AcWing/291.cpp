#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=12,M=1<<N;
int n,m;
int f[N][M];
int book[M];
int check(int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        int j=i;
        cnt=0;
        while(!((x>>j)&1)&&j<n){
            j++;
            cnt++;
        }
        if(cnt&1){book[x]=0;return 0;}
        i=j;
    }
    book[x]=1;
    return 1;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>m,n||m){
        vector<int>state;
        vector<int>head[M];
        for(int i=0;i<1<<n;i++){
            if(check(i)){
                state.emplace_back(i);
            }
        }
        for(int i=0;i<1<<n;i++){
            for(auto j=0;j<1<<n;j++){
                if(!(i&j)&&book[i|j]){
                    head[i].emplace_back(j);
                }
            }
        }
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<=m;i++){
            for(int k=0;k<1<<n;k++){//第i-1列
                for(auto j:head[k]){//第i列
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
    return 0;
}