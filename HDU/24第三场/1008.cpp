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
    int n,m,k;cin>>n>>m>>k;
    vector<PII>v[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    vector<int>d(n+1,INF);d[1]=0;
    function<void()> Dijkstra=[&](){
        vector<int>book(n+1);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        for(int i=1;i<=n;i++)if(d[i]!=INF)q.push({d[i],i});
        while(q.size()){
            auto [dist,t]=q.top();
            q.pop();
            if(book[t])continue;
            book[t]=1;
            for(auto &[j,w]:v[t]){
                if(book[j])continue;
                if(w+dist<d[j]){
                    d[j]=w+dist;
                    q.push({d[j],j});
                }
            }
        }
    };

    Dijkstra();
    for(int i=1;i<=n;i++){
        d[i]=min(d[i],(i|1)*k);
        for(int j=(i-1)&i;j;j=(j-1)&i){
            d[i]=min(d[i],d[j]+i*k);
        }
    }
    Dijkstra();

    for(int i=2;i<=n;i++){
        cout<<d[i]<<' ';
    }cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}