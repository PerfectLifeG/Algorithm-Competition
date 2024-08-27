#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v[m];
    for(int k=0;k<n;k++){
        for(int i=0;i<m;i++){
            int a;cin>>a;
            v[i].emplace_back(a);
        }
    }
    for(int i=0;i<m;i++){
        sort(all(v[i]));
    }
    vector<int>s;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<m;j++){
            t+=v[j][i];
        }
        s.emplace_back(t);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans-s[i]*(n-1-i)+s[i]*i;
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