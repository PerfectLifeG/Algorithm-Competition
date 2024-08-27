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
vector<int>val(N);
vector<int>v[N];
vector<int>f(N);
vector<int>sum(N);
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++)
    {
        v[i].clear();val[i]=0;f[i]=0;sum[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<int>tm(n+1);
    for(int i=1;i<=n;i++){
        cin>>tm[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    function<void(int,int)> dfs=[&](int t,int fa){
        int mx=0;
        int mx1=0,id1;
        int mx2=0;
        for(auto j:v[t]){
            if(j==fa)continue;
            dfs(j,t);
            sum[t]+=f[j];
            mx=max(mx,val[j]);
            if(val[j]-f[j]+sum[j]>mx1){
                mx2=max(mx2,mx1);
                mx1=val[j]-f[j]+sum[j];
                id1=j;
            }else mx2=max(mx2,val[j]-f[j]+sum[j]);
        }
        f[t]=max(f[t],sum[t]+mx);
        for(auto j:v[t]){
            if(j==fa)continue;
            if(tm[j]==3){
                if(j==id1){
                    f[t]=max(f[t],sum[t]+val[j]+mx2);
                }else{
                    f[t]=max(f[t],sum[t]+val[j]+mx1);
                }
            }
        }
    };
    dfs(1,-1);
    cout<<f[1]+val[1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}