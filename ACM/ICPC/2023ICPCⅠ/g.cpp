#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f;
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
    return ksm(a,mod-2);
}
int root[N];
int sz[N];int depth[N];
int find(int a){
    if(a==root[a])return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(depth[ra]>depth[rb])swap(ra,rb);
    root[rb]=ra;
    sz[ra]=(sz[ra]+sz[rb])%mod;
}
void solve(){
    int n;cin>>n;
    vector<PII>ed(n);
    for(int i=1;i<=n;i++)root[i]=i,sz[i]=1,depth[i]=0;
    for(int i=0;i<n-1;i++){
        cin>>ed[i].x>>ed[i].y;
    }
    vector<int>v[n+1];
    vector<int>fa(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fa[1]=1;depth[1]=1;
    function<void(int,int)>dfs=[&](int t,int f){
        for(auto j:v[t]){
            if(j==f)continue;
            fa[j]=t;
            depth[j]=depth[t]+1;
            dfs(j,t);
        }
    };
    dfs(1,1);
    // for(int i=1;i<=n;i++)cout<<i<<' '<<depth[i]<<endl;
    int ans=1;
    for(int i=0;i<n-1;i++){
        if(find(fa[find(ed[i].x)])==find(ed[i].y)){
            ans=ans*sz[find(ed[i].y)]%mod*sz[find(ed[i].x)]%mod;
            merge(ed[i].x,ed[i].y);
        }else if(find(fa[find(ed[i].y)])==find(ed[i].x)){
            ans=ans*sz[find(ed[i].y)]%mod*sz[find(ed[i].x)]%mod;
            merge(ed[i].x,ed[i].y);
        }else {cout<<0<<endl;return;}
        // cout<<i<<' '<<ans<<endl;
    }
    // cout<<1*inv(6)<<endl;
    cout<<inv(ans)<<endl; 
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}