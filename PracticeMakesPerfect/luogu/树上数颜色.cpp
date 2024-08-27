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
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>col(n+1);
    for(int i=1;i<=n;i++)cin>>col[i];

    vector<int>dfn(n+1);int idx=1;
    vector<int>adfn(n+1);
    vector<int>sz(n+1);
    vector<int>son(n+1);
    vector<int>cnt(n+1);
    function<int(int,int)> dfs1=[&](int t,int fa)->int{
        sz[t]=1;
        dfn[t]=idx;
        adfn[idx++]=t;
        for(auto j:v[t]){
            if(j==fa)continue;
            sz[t]+=dfs1(j,t);
            if(sz[j]>sz[son[t]])son[t]=j;
        }
        return sz[t];
    };
    dfs1(1,1);
    vector<int>book(n+1);
    for(int i=1;i<=n;i++)book[son[i]]=1;

    vector<int>ans(n+1);
    int sum=0;
    function<void(int,int)> dfs2=[&](int t,int fa){
        for(auto j:v[t]){
            if(j==fa||j==son[t])continue;
            dfs2(j,t);
        }
        if(son[t])dfs2(son[t],t);
        if(!cnt[col[t]])sum++;cnt[col[t]]++;
        for(auto j:v[t]){
            if(j==fa||j==son[t])continue;
            for(int i=dfn[j];i<dfn[j]+sz[j];i++){
                int p=adfn[i];
                if(!cnt[col[p]])sum++;
                cnt[col[p]]++;
            }
        }
        ans[t]=sum;
        if(!book[t]){
            cnt[col[t]]--;
            for(auto j:v[t]){
                if(j==fa)continue;
                for(int i=dfn[j];i<dfn[j]+sz[j];i++){
                    int p=adfn[i];
                    cnt[col[p]]--;
                }
            }
            sum=0;
        }
    };
    dfs2(1,1);

    int q;cin>>q;
    while(q--){
        int a;cin>>a;
        cout<<ans[a]<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}