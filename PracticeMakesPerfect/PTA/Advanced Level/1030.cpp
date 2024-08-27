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
const int N=550;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,m,st,ed;
vector<array<int,3>>v[N];
void dijkstra(){
    vector<int>pre(n);
    vector<int>book(n);
    vector<int>d(n,1e18);d[st]=0;
    vector<int>d2(n,1e18);d2[st]=0;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    q.push({0,0,st});
    while(q.size()){
        auto [dis1,dis2,t]=q.top();
        q.pop();
        if(t==ed)break;
        if(book[t])continue;
        book[t]=1;
        for(auto [j,w1,w2]:v[t]){
            if(d[j]>=w1+dis1){
                if(d[j]>w1+dis1||d[j]==w1+dis1&&d2[j]>w2+dis2){
                    d[j]=w1+dis1;
                    d2[j]=w2+dis2;
                    pre[j]=t;
                    q.push({d[j],d2[j],j});
                }
            }
        }
    }
    vector<int>ans;
    for(int i=ed;i!=st;i=pre[i]){
        ans.push_back(i);
    }
    cout<<st;
    for(int i=ans.size()-1;i>=0;i--)cout<<' '<<ans[i];
    cout<<' '<<d[ed]<<' '<<d2[ed]<<endl;
}
void solve(){
    cin>>n>>m>>st>>ed;
    for(int i=0;i<m;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        v[a].push_back({b,c,d});
        v[b].push_back({a,c,d});
    }
    dijkstra();
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}