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
    int n,m;cin>>n>>m;
    vector<int>v[n+1];
    map<PII,int>mp;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        mp[{a,b}]=1;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int>col(n+1);
    int cnt=0;
    vector<int>v1,v2;
    function<void(int,int)> dfs=[&](int t){
        if(col[t]==1)v1.push_back(t);
        else v2.push_back(t);
        for(auto j:v[t]){
            if(!col[j]){
                col[j]=-col[t];
                dfs(j);
            }
        }
    };

    int f1=0,f2=0;
    for(int i=1;i<=n;i++){
        if(!col[i]){
            if(f1){
                col[i]=-1;
                f2=i;
                dfs(i);
                continue;
            }
            col[i]=1;
            dfs(i);
            f1=i;
        }
    }

    // for(int i=1;i<=n;i++)cout<<i<<' '<<col[i]<<endl;

    if(!f2){
        for(int i=1;i<=n;i++){
            if(col[i]==-1&&v[i].size()!=v1.size()){
                for(int j=1;j<=n;j++){
                    if(col[j]!=1)continue;
                    auto [a,b]=minmax(i,j);
                    if(!mp.count({a,b})){
                        f1=j,f2=i;
                        break;
                    }
                }
                break;
            }
        }
    }

    if(!f2){cout<<-1<<endl;return;}

    for(auto i:v1){
        if(i!=f1)cout<<i<<' ';
    }cout<<f1<<' '<<f2<<' ';
    for(auto i:v2){
        if(i!=f2)cout<<i<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}