#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,v;cin>>n>>v;
    vector<int>w(n+1);
    vector<int>d(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    // int idx=1;
    // for(int i=1;i<=n;i++){
    //     if(i==idx){
    //         if(d[i]<0)idx++;
    //         continue;
    //     }
    //     if(d[i]>=0){
    //         d[idx]+=d[i];
    //         w[idx]+=w[i];
    //     }else{
    //         idx++;
    //         d[idx]=d[i];
    //         w[idx]=w[i];
    //     }
    // }
    // idx=min(idx,n);
    for(int i=1;i<=n;i++){
        w[i]+=w[i-1];
        d[i]+=d[i-1];
    }
    vector<int>f(n+1,-1e18);f[0]=0;
    int now=0;int lst=1;
    for(int i=1;i<=n;i++){
        if(w[i]-w[lst-1]<v)continue;
        if(w[i]-w[lst-1]>=v)f[i]=f[i-1]+d[i]-d[i-1];
        int flag=0;
        for(int j=lst+1;j<=i;j++){
            if(w[i]-w[j-1]<v)break;
            if(f[i]<=d[i]-d[j-1]){
                flag=1;
                f[i]=d[i]-d[j-1];
                lst=j;
            }
        }
        if(!flag)lst=i;
    }
    int ans=-1e18;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int _=1;
    while(_--)solve();
    return 0;
}