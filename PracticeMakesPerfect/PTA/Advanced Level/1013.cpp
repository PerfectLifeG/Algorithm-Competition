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
    int n,m,k;cin>>n>>m>>k;
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root;
    int ans=0;
    vector<int>book(n+1);
    function<int(int,int)> dfs=[&](int t,int fa)->int{
        int flag=0;
        if(!book[t]&&t!=root)flag=1;
        book[t]=1;
        for(auto j:v[t]){
            if(j==fa||book[j]||j==root||t==root)continue;
            if(dfs(j,t))flag=1;
        }
        return flag;
    };
    for(int i=0;i<k;i++){
        cin>>root;ans=0;
        for(int j=1;j<=n;j++)if(dfs(j,-1))ans++;
        for(int j=0;j<=n;j++)book[j]=0;
        cout<<max(0ll,ans-1)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}