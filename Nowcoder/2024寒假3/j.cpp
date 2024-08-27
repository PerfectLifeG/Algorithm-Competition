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
    vector<int>v1(n+1);
    vector<int>v2(m+1);
    vector<double>ans1(n+1,1.0);
    vector<double>ans2(m+1,1.0);
    vector<PII>edge;
    for(int i=0;i<k;i++){
        int u,v;cin>>u>>v;
        edge.push_back({u,v});
        v1[u]++;
        v2[v]++;
    }
    for(auto [i,j]:edge){
        ans1[i]*=1.0*(v2[j]-1)/v2[j];
        ans2[j]*=1.0*(v1[i]-1)/v1[i];
    }
    double t1=0,t2=0;
    for(int i=1;i<=n;i++){
        t1+=1.0-ans1[i];
    }
    for(int i=1;i<=m;i++){
        t2+=1.0-ans2[i];   
    }
    cout<<"float\n";
    cout<<fixed<<setprecision(20)<<t1<<' '<<t2<<endl;;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}