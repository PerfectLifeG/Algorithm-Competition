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
const int N=1050;
const int mod=998244353;
const int INF=0x3f3f3f3f;
vector<PII>v[N];
struct Node{
    int idx;
    double mx;
    double avg;
    bool operator<(const Node& n)const{
        if(mx!=n.mx){
            return mx>n.mx;
        }
        if(avg!=n.avg){
            return avg<n.avg;
        }
        return idx<n.idx;
    }
};
vector<Node>ans;
int n,ds;
void dijkstra(int st){
    priority_queue<PII,vector<PII>,greater<PII>>q;
    vector<int>d(N,1e18);d[st]=0;
    vector<int>book(N);
    q.push({0,st});
    while(q.size()){
        auto [dist,t]=q.top();
        q.pop();
        if(book[t])continue;
        book[t]=1;
        for(auto [j,w]:v[t]){
            if(book[j])continue;
            if(d[j]>w+dist){
                d[j]=w+dist;
                q.push({d[j],j});
            }
        }
    }
    int sum=0;
    int mx=1e9;
    int flag=1;
    // cout<<st<<endl;
    for(int i=1;i<=n;i++){
        sum+=d[i];
        // cout<<d[i]<<' ';
        if(d[i]>ds){flag=0;break;}
        mx=min(mx,d[i]);
    }
    // cout<<endl;
    if(flag){
        ans.push_back({st-1000,mx,1.0*sum/n});
    }
}
void solve(){
    int m,k;cin>>n>>m>>k>>ds;
    for(int i=0;i<k;i++){
        string a,b;cin>>a>>b;
        int c;cin>>c;
        int u,w;
        if(a[0]=='G'){a=a.substr(1);u=1000+stoi(a);}
        else u=stoi(a);
        if(b[0]=='G'){b=b.substr(1);w=1000+stoi(b);}
        else w=stoi(b);
        v[u].push_back({w,c});
        // cout<<u<<' '<<w<<' '<<c<<endl;
        v[w].push_back({u,c});
    }
    for(int i=1;i<=m;i++){
        dijkstra(i+1000);
    }
    if(!ans.size())cout<<"No Solution\n";
    else{
        sort(all(ans));
        cout<<'G'<<ans[0].idx<<endl;
        cout<<fixed<<setprecision(1)<<ans[0].mx<<' '<<ans[0].avg<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}