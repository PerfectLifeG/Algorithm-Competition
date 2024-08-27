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
const int N=1e5+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dfn[N];int idx=1;
vector<int>v[N];
int a[N];
int mn[N];
int mx[N];
void dfs(int t){
    mn[t]=a[t];
    mx[t]=a[t];
    for(auto j:v[t]){
        dfs(j);
        mn[t]=min(mn[t],mn[j]);
        mx[t]=max(mx[t],mx[j]);
    }
}
void solve(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int fa;cin>>fa;
        v[fa].push_back(i);
    }
    for(int i=1;i<=n;i++){int t;cin>>t;a[t]=i;}
    dfs(1);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)ans[mn[i]]++,ans[mx[i]]--;
    for(int i=1;i<=n;i++){ans[i]+=ans[i-1];cout<<ans[i]<<' ';}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}