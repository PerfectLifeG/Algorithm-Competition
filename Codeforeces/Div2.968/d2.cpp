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
    int n,m;cin>>n>>m;
    int mx=0;
    int mx2=0;
    vector<PII>tmp;
    set<PII>tmp2;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        unordered_map<int,int>mp;
        for(int j=0;j<k;j++){
            int a;cin>>a;
            mp[a]=1;
        }
        int f=0;
        int u,v;
        for(int i=0;i<=k+1;i++){
            if(!mp.count(i)){
                if(f==0){
                    f=1;
                    u=i;
                    continue;
                }
                v=i;
                break;
            }
        }
        tmp.push_back({u,v});
        tmp2.insert({u,v});
        // cout<<i<<' '<<mex<<endl;
        mx=max(mx,v);
        mx2=max(mx2,u);
    }
    // cout<<endl;
    vector<vector<int>> g(mx+1);
    vector<int>cnt(mx+1);
    for(auto [u,v]:tmp){
        cnt[u]++;
        // cout<<u<<' '<<v<<endl;
    }
    for(auto [u,v]:tmp2){
        g[u].push_back(v);
        // cout<<u<<' '<<v<<endl;
    }

    // return;
    // cout<<cnt<<endl;
    vector<int>book(mx+1,-1);
    function<void(int)> dfs=[&](int u){
        book[u]=u;
        for(auto v:g[u]){
            if(book[v]==-1)dfs(v);
            book[u]=max(book[u],book[v]);
        }
    };

    for(int i=0;i<=mx;i++){
        if(book[i]!=-1)continue;
        dfs(i);
    }
    // cout<<endl;
    // for(int i=0;i<=mx;i++){
    //     cout<<i<<' '<<book[i]<<endl;
    // }
    // return;

    for(int i=0;i<=mx;i++){
        // cout<<i<<' '<<book[i]<<endl;
        if(cnt[i]>1)mx2=max(mx2,book[i]);
    }
    // cout<<mx2<<endl;
    int ans=0;
    // cout<<m<<' '<<mx<<endl;
    // return;
    for(int i=min(m,mx);i>=0;i--){
        // cout<<i<<' '<<book[i]<<endl;
        book[i]=max(book[i],mx2);
        ans+=book[i];
        // cout<<i<<' '<<book[i]<<endl;
    }
    // cout<<ans<<' '<<mx<<' '<<m<<endl;
    if(m>mx)ans+=(mx+1+m)*(m-mx)/2;
    // cout<<mx<<endl;
    // int ans=0;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}