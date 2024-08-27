#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
const int N=5050;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,m,l,base;
vector<array<int,3>>v[N];
int dijkstra(int color){
    vector<int>d(n+1,1e18);d[1]=0;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,1,color});
    while(q.size()){
        auto [p,t,c]=q.top();
        if(t==n)break;
        q.pop();
        for(auto [j,w,cc]:v[t]){
            if(c==cc){
                if(d[j]>=d[t]+w){
                    d[j]=d[t]+w;
                    q.push({d[j],j,cc});
                }
            }else{
                if(d[j]>=d[t]+w*base){
                    d[j]=d[t]+w*base;
                    q.push({d[j],j,cc});
                }
            }
        }
    }
    return d[n];
}
void solve(){
    cin>>n>>m>>l>>base;
    for(int i=0;i<m;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        v[a].push_back({b,d,c});
    }
    int ans=1e18;
    for(int i=1;i<=l;i++){
        ans=min(ans,dijkstra(i));
    }
    if(ans==1e18){cout<<-1<<endl;}
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}