#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
const int mod=1e9+7;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>>f(n+1,vector<int>(64));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][a[i]]=1;
        for(int j=0;j<=63;j++){
            f[i][j]=(f[i][j]+f[i-1][j])%mod;//不选a[i]
            f[i][a[i]&j]=(f[i][a[i]&j]+f[i-1][j])%mod;//选a[i]
        }
    }
    int ans=0;
    for(int i=0;i<=63;i++){
        if(__builtin_popcountll(i)==k)ans=(ans+f[n][i])%mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}