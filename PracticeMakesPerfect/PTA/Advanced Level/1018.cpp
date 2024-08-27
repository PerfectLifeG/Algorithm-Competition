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
int n;
vector<int>d(N,1e9);
vector<PII>v[N];
int a[N];
int st,ed;
void dijkstra(){
    vector<int>book(n+1);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,st});
    book[st]=1;d[st]=0;
    for(int i=0;i<n;i++){
        auto t=q.top().second;
        q.pop();
        book[t]=1;
        for(auto [j,w]:v[t]){
            if(book[j])continue;
            if(d[j]>d[t]+w){
                d[j]=d[t]+w;
                q.push({d[j],j});
            }
        }
    }
}
vector<int>tmp;
vector<int>ans;
int sum=1e18;
int sum2=1e18;
int mx;
void dfs(int t,int fa,int dist,int s,int s2,int pre){
    if(t!=st)tmp.push_back(t);
    if(t==ed){
        int post=max(0ll,pre+s-s2);
        if(pre<=sum){
            if(pre<sum||post<sum2){
                sum=pre;
                sum2=post;
                ans=tmp;
            }
        }
        return;
    }
    for(auto [j,w]:v[t]){
        if(j==fa)continue;
        if(dist+w!=d[j])continue;
        dfs(j,t,dist+w,s+a[j],s2+mx,max(pre,max(0ll,s2+mx-s-a[j])));
        tmp.pop_back();
    }
}
void solve(){
    int m;cin>>mx>>n>>ed>>m;mx/=2;
    for(int i=1;i<=n;i++){int t;cin>>t;a[i]=t;}
    for(int i=0;i<m;i++){
        int t,b,c;cin>>t>>b>>c;
        v[t].push_back({b,c});
        v[b].push_back({t,c});
    }
    dijkstra();
    dfs(0,-1,0,0,0,0);
    cout<<sum<<' '<<0;
    for(auto i:ans){
        cout<<"->"<<i;
    }
    cout<<' '<<sum2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}