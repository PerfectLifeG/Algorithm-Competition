#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int val[N];
int mx[N];
int sum[N];
map<int,int>mp[N];
vector<int>v[N];
void dfs(int t,int fa){
    mp[t][val[t]]++;
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs(j,t);
        // cout<<t<<' '<<mx[t]<<' '<<sum[t]<<endl;
        // for(auto i:mp[t])cout<<i.x<<' '<<i.y<<'|';cout<<endl;
        // for(auto i:mp[j])cout<<i.x<<' '<<i.y<<'|';cout<<endl;
        if(mp[t].size()<mp[j].size())swap(mp[t],mp[j]);
        for(auto i:mp[j]){
            mp[t][i.first]+=i.second;
            // if(mp[t][i.first]>mx[t]){
            //     mx[t]=mp[t][i.first];
            //     sum[t]=i.first;
            // }else if(mp[t][i.first]==mx[t]){
            //     sum[t]+=i.first;
            // }
        }
        // mp[j].clear();
    }
    for(auto [i,j]:mp[t]){
        if(j>mx[t]){
            mx[t]=j;
            sum[t]=i;
        }else if(j==mx[t]){
            sum[t]+=i;
        }
    }
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)cout<<sum[i]<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}