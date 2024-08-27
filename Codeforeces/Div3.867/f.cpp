#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;

void solve(){
    int n,k,c;cin>>n>>k>>c;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>depth(n+1);
    int ans=0;
    int mx=0;
    function<void(int,int,int)>dfs=[&](int t,int fa,int d){
        depth[t]=1;
        int mx1=0,mx2=0;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t,d+1);
            depth[t]=max(depth[t],depth[j]+1);
            if(mx1<=depth[j]){
                mx2=mx1;
                mx1=depth[j];
            }else{
                mx2=max(mx2,depth[j]);
            }
        }
        // cout<<t<<' '<<mx1<<' '<<mx2<<endl;
        ans=max(ans,mx1*k+mx2*k-(mx2+d)*c);
        // cout<<t<<' '<<ans<<endl;
        mx=max(mx,d);
    };
    dfs(1,0,0);
    ans=max(ans,mx*k);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}