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
    int dep[n+1]={};
    vector<int>v[100];
    for(int i=0;i<m;i++){
        int a;cin>>a;
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int b;cin>>b;
            v[a].push_back(b);
        }
    }
    function<void(int,int)> dfs=[&](int t,int depth){
        dep[depth]++;
        for(auto j:v[t]){
            dfs(j,depth+1);
        }
    };

    dfs(1,1);

    int ans=1;int mx=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>mx){
            mx=dep[i];
            ans=i;
        }
    }
    cout<<mx<<' '<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}