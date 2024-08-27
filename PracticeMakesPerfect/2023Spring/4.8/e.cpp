#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int n,m;
int a[N];
int b[N];
int d[N];
void solve(){
    cin>>n>>m;
    vector<vector<int>>e(n+1);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        e[b[i]].push_back(a[i]);
    }
    vector<int>q;
    memset(d,-1,sizeof d);
    q.push_back(1);d[1]=0;
    for(int i=0;i<q.size();i++){
        auto t=q[i];
        for(auto j:e[t]){
            if(d[j]!=-1)continue;
            d[j]=d[t]+1;
            q.push_back(j);
        }
    }
    if(q.size()<n){
        cout<<"INFINITE"<<endl;
        return;
    }
    vector<vector<int>>f(n+1);
    for(auto x:q){
        for(int i=0;i<=d[x];i++){
            f[i].push_back(x);
        }
    }
    vector<int>ans;
    for(auto &x:f){
        ans.insert(ans.end(),x.rbegin(),x.rend());
    }
    cout<<"FINITE"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}