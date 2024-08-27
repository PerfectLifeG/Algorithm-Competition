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
const int N=1e6+10;
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
int inv(int a){
    a%=mod;
    return ksm(a,mod-2);
}
vector<int>v[N];
int cnt1[N];
int cnt2[N];//ye
void dfs(int t,int fa,int dep){
    int f=0;
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs(j,t,dep+1);
        f=1;
    }
    cnt1[dep]++;
    if(!f)cnt2[dep]++;
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1,0);
    vector<int>p(n+1);
    p[0]=1;
    int ans=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*(cnt1[i]-cnt2[i])%mod*inv(cnt1[i])%mod;
        ans+=p[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}