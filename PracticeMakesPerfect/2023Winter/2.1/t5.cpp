#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=100010;
int b[N],x[N],f[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i]>>x[i];
    }
    memset(f,0x3f,sizeof f);f[n]=0;
    for(int i=n;i>=0;i--){
        for(int j=1;j<=m;j++){
            if(x[j]>i)continue;
            int res = i-(i%x[j]);
            f[res]=min(f[res],f[i]+b[j]);
        }
    }
    for(int i=0;i<n;i++){
        if(f[i]<INF/2)cout<<f[i];
    }
    return 0;
}