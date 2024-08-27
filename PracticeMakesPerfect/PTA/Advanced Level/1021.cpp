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
    int n;cin>>n;
    vector<int>v[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>depth(n+1);
    int root;int len=0;
    function<void(int,int)> dfs=[&](int t,int fa){
        for(auto j:v[t]){
            if(j==fa)continue;
            if(depth[j])continue;
            depth[j]=depth[t]+1;
            dfs(j,t);
        }
        if(len<=depth[t]){
            len=depth[t];
            root=t;
        }
    };

    set<int>ans;
    function<void(int,int,int)> dfs2=[&](int t,int fa,int depth){
        if(depth==len)ans.insert(t);
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs2(j,t,depth+1);
        }
    };

    int k=0;
    for(int i=1;i<=n;i++){
        if(!depth[i]){
            dfs(i,-1);
            k++;
        }
    }
    if(k>1){cout<<"Error: "<<k<<" components\n";return;}

    int t=root;
    depth.assign(n+1,0);
    dfs(root,-1);
    dfs2(t,-1,0);
    dfs2(root,-1,0);
    for(auto i:ans){
        cout<<i<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}