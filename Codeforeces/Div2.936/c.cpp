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
void solve(){
    int n,k;cin>>n>>k;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans=0;
    vector<int>sz(n+1);
    int mid;
    function<void(int,int)> dfs=[&](int t,int fa){
        sz[t]=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            sz[t]+=sz[j];
        }
        if(sz[t]>=mid)ans++,sz[t]=0;
    };

    int l=1,r=n+1;
    while(l+1!=r){
        mid=l+r>>1;
        ans=0;
        dfs(1,1);
        if(ans>k)l=mid;
        else r=mid;
    }
    cout<<l<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}