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

vector<int>v[41];
int book[41];
map<PII,int>mp;
int val[41];
int dfs(int t,int fa,int st,int dep){
    cout<<t<<' '<<fa<<' '<<st<<' '<<dep<<endl;
    int flag=0;
    for(auto j:v[t]){
        if(j==fa||book[j])continue;
        book[j]=1;
        // cout<<j<<' ';
        st|=(1ll<<j);
        flag|=(1ll<<j);
    }
    // cout<<endl;

    if(mp.count({t,st})){
        return dep+mp[{t,st}];
    }
    mp[{t,st}]=dep;


    int mx=0;
    for(auto j:v[t]){
        if(j==fa)continue;
        if((flag>>j)&1){
            mx=max(mx,dfs(j,t,st,dep+1));
        }
    }

    for(auto j:v[t]){
        if(j==fa)continue;
        if((flag>>j)&1){
            book[j]=0;
        }
    }

    return mx+dep;
}

void solve(){
    int n=40,m;
    // cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v[i].push_back(j);
            v[j].push_back(i);
        }
    }

    // for(int i=0;i<m;i++){
    //     int a,b;cin>>a>>b;
    //     v[a].push_back(b);
    //     v[b].push_back(a);
    // }

    int ans=0;
    for(int i=1;i<=n;i++){
        book[i]=1;
        // ans=max(ans,dfs(i,i,1ll<<i,1));
        dfs(i,i,1ll<<i,1);
        cout<<endl;
        book[i]=0;
    }
    // for(int i=0;i<n;i++){
    // }
    cout<<ans<<endl;
    // cout<<mp.size()<<endl;


}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}