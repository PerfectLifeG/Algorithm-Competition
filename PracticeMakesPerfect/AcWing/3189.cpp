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
    int n;cin>>n;
    vector<int>v[n+1];
    vector<int>val(n+1);
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int>son(n+1);
    vector<int>sz(n+1);
    
    function<int(int,int)> dfs1=[&](int t,int fa)->int{
        sz[t]=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            sz[t]+=dfs1(j,t);
            if(sz[j]>sz[son[t]])son[t]=j;
        }
        return sz[t];
    };

    vector<int>ans(n+1);
    vector<int>cnt(n+1);
    vector<int>book(n+1);
    int mx=0,sum=0,flag2=0;
    function<void(int,int,int)> dfs3=[&](int t,int fa,int flag){
        cnt[val[t]]+=flag;
        if(cnt[val[t]]>mx)mx=cnt[val[t]],sum=val[t];
        else if(cnt[val[t]]==mx)sum+=val[t];
        for(auto j:v[t]){
            if(j==fa||j==flag2)continue;
            dfs3(j,t,flag);
        }
    };

    function<void(int,int)> dfs2=[&](int t,int fa){
        for(auto j:v[t]){
            if(j==fa||j==son[t])continue;
            dfs2(j,t);
        }
        if(son[t])dfs2(son[t],t);
        flag2=son[t];
        dfs3(t,fa,1);
        ans[t]=sum;
        if(!book[t]){
            flag2=0;
            dfs3(t,fa,-1);
            mx=0,sum=0;
        }
    };

    dfs1(1,1);
    for(int i=1;i<=n;i++)book[son[i]]=1;
    dfs2(1,1);

    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}