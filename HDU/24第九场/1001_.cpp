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
const int INF=0x3f3f3f3f3f3f3f3f;

int ksm(int a,int n){
    int r=1ll;
    while(n){
        if(n&1)r=r*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return r;
}

void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>>g(n+1);
    for(int i=2;i<=n;i++){
        int f;cin>>f;
        g[f].push_back(i);
        g[i].push_back(f);
    }


    int dp[N];
    function<PII(int,int)> dfs=[&](int u, int fa)->PII{
        if(g[u].size()==1){
            return {1,1};
        }
        int cnt=0;
        int r=1;
        for(auto v:g[u]){
            if(v==fa)continue;
            PII res=dfs(v,u);
            r*=res.second;r%=mod;
            cnt+=res.first;cnt%=mod;
        }
        if(cnt){
            if((cnt+1)&1)r=r%mod*ksm(2*C(cnt+1,(cnt+1)/2)%mod,k)%mod;
            else r=r*ksm(C(cnt+1,(cnt+1)/2)%mod,k)%mod;
            r%=mod;
        }
        return {0,r};
    };
    cout<<dfs(1,1).second<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}