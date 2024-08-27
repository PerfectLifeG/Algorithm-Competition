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
    int n,st,ed,m;cin>>n>>st>>ed>>m;
    vector<array<int,3>>v[n+1];
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a].push_back({b,c,d});
        v[b].push_back({a,c,d});
    }
    vector<int>d1(n+1,INF);d1[st]=0;
    vector<int>d2(n+1,INF);d2[ed]=0;
    auto Dijkstra1=[&](){
        vector<int>book(n+1);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({0,st});
        while(q.size()){
            auto [dist,t]=q.top();
            q.pop();
            if(book[t])continue;
            book[t]=1;
            for(auto [j,a,b]:v[t]){
                if(book[j])continue;
                if(d1[j]>dist+a){
                    d1[j]=dist+a;
                    q.push({d1[j],j});
                }
            }
        }
    };
    auto Dijkstra2=[&](){
        vector<int>book(n+1);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({0,ed});
        while(q.size()){
            auto [dist,t]=q.top();
            q.pop();
            if(book[t])continue;
            book[t]=1;
            for(auto [j,a,b]:v[t]){
                if(book[j])continue;
                if(d2[j]>dist+b){
                    d2[j]=dist+b;
                    q.push({d2[j],j});
                }
            }
        }
    };
    Dijkstra1();
    Dijkstra2();
    int ans=INF;
    // for(int i=1;i<=n;i++)cout<<d1[i]<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)cout<<d2[i]<<' ';cout<<endl;
    for(int i=1;i<=n;i++){
        ans=min(ans,d1[i]+d2[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}