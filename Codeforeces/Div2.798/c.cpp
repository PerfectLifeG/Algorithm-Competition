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
    vector<int>v2[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>sz(n+1);
    function<void(int,int)> dfs=[&](int t,int fa){
        sz[t]=1;
        for(auto j:v[t]){
            if(j==fa)continue;
            v2[t].push_back(j);
            dfs(j,t);
            sz[t]+=sz[j];
        }
    };

    dfs(1,1);
    int val[n+1][2]={};
    function<void(int)> dfs2=[&](int t){
        for(auto j:v2[t]){
            dfs2(j);
        }
        if(v2[t].size()==1){
            val[t][1]=sz[t]-1;
            val[t][0]=val[v2[t][0]][1];
        }else if(v2[t].size()==2){
            val[t][1]=sz[t]-1;
            val[t][0]=max(val[v2[t][0]][0]+val[v2[t][1]][1],val[v2[t][0]][1]+val[v2[t][1]][0]);
        }
    };
    dfs2(1);
    cout<<val[1][0]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}