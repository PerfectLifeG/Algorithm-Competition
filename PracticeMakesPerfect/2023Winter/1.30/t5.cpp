#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
#define int long long
const int N=110;
int f[N];
int w[N],v[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    int res=f[m];
    for(int k=1;k<=n;k++){
        int t=w[k];
        w[k]=-1;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            for(int j=m;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
        if(f[m]<res){cout<<0<<endl;w[k]=t;continue;}
        w[k]=INF;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            for(int j=m;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
        w[k]=t;
        cout<<res-(f[m]-INF+t)+1<<endl;
    }
    return 0;
}