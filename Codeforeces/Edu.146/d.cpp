#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root1=0,mx=0;
    function<void(int,int,int)> dfs1=[&](int t,int fa,int d){
        if(d>mx){
            mx=d;
            root1=t;
        }
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs1(j,t,d+1);
        }
    };
    dfs1(1,-1,0);
    vector<int>farlen(n+1);
    mx=0;int root2=0;
    function<void(int,int,int)> dfs2=[&](int t,int fa,int d){
        if(d>mx){
            mx=d;
            root2=t;
        }
        farlen[t]=max(farlen[t],d);
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs2(j,t,d+1);
        }
    };
    dfs2(root1,-1,0);
    dfs2(root2,-1,0);
    // for(int i=1;i<=n;i++)cout<<i<<' '<<farlen[i]<<endl;
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        ans[farlen[i]+1]++;
    }
    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
        cout<<min(n,ans[i]+1)<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}