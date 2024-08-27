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
    int ta,me;cin>>ta>>me;
    map<pair<int,int>,int>mp;
    vector<int>p;
    for(int i=0;i<k;i++){
        int a;cin>>a;
        p.push_back(a);
    }
    vector<PII>v[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        mp[{a,b}]=c;
        mp[{b,a}]=c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    vector<int>d(n+1,INF);d[me]=0;
    function<void()> Dijkstra=[&](){
        vector<int>book(n+1);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({0,me});
        while(q.size()){
            auto [dis,t]=q.top();
            q.pop();
            if(book[t])continue;
            book[t]=1;
            for(auto [j,w]:v[t]){
                if(book[j])continue;
                if(d[j]>dis+w){
                    d[j]=dis+w;
                    q.push({d[j],j});
                }
            }
        }
    };

    Dijkstra();

    vector<int>d2(n+1,INF);d2[ta]=0;
    int lst=ta;
    for(int i=1;i<k;i++){
        d2[p[i]]=d2[lst]+mp[{lst,p[i]}];
        lst=p[i];
    }

    // for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<endl;
    // for(int i=1;i<=n;i++)cout<<d2[i]<<' ';cout<<endl;

    int ans=-1;
    for(int i=1;i<=n;i++){
        if(d[i]!=INF&&d2[i]!=INF&&d2[i]>=d[i])ans=max(ans,d2[i]-d[i]);
    }
    if(ans!=-1)cout<<ans<<endl;
    else cout<<-1<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}